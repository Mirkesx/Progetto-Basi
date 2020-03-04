/*
	Trigger che aumenta di uno il numero di recensioni per un film quando ne viene inserita una
*/

CREATE TRIGGER aumenta_n_recensione
after insert on streaming_film.recensioni
for each row
UPDATE film
set n_recensioni = n_recensioni + 1
where film.idfilm = new.idfilm

/*
	Trigger che riduce di uno il numero di recensioni per un film quando ne viene eliminata una
*/

CREATE TRIGGER riduci_n_recensione
after delete on streaming_film.recensioni
for each row
UPDATE film
set n_recensioni = n_recensioni - 1
where film.idfilm = old.idfilm

/*
	Calcola la media dei rating ogni volta che viene aggiunto un nuovo rating
*/

DELIMITER //

CREATE TRIGGER calcola_mediarating_aumento
after insert on streaming_film.recensioni
for each row
BEGIN
	DECLARE somma DOUBLE;
	DECLARE n INTEGER;
	
	select count(*), sum(rating) into n,somma
	from streaming_film.recensioni
	where recensioni.idfilm = new.idfilm
	group by idfilm;
	
	UPDATE streaming_film.film
	set film.mediarating = somma/n
	where film.idfilm = new.idfilm;
END//

DELIMITER ;

/*
	Calcola la media dei rating ogni volta che viene modificato un rating esistente
*/

DELIMITER //

CREATE TRIGGER calcola_mediarating_modifica
after update on streaming_film.recensioni
for each row
BEGIN
	DECLARE somma DOUBLE;
	DECLARE n INTEGER;
	
	select count(*), sum(rating) into n,somma
	from streaming_film.recensioni
	where recensioni.idfilm = new.idfilm
	group by idfilm;
	
	UPDATE streaming_film.film
	set film.mediarating = somma/n
	where film.idfilm = new.idfilm;
END//

DELIMITER ;


/*
	Calcola la media dei rating ogni volta che viene eliminato un rating esistente
*/

DELIMITER //

CREATE TRIGGER calcola_mediarating_riduci
after delete on streaming_film.recensioni
for each row
BEGIN
	DECLARE somma DOUBLE;
	DECLARE n INTEGER;
	DECLARE media DOUBLE;
	
	select count(*), sum(rating) into n,somma
	from streaming_film.recensioni
	where recensioni.idfilm = old.idfilm
	group by idfilm;
	
	if n > 0 then
		SET media = somma/n;
	else
		SET media = 0;
	end if;
	
	UPDATE streaming_film.film
	set film.mediarating = media
	where film.idfilm = old.idfilm;
END//

DELIMITER ;

/*
	Evita che si modifichi il valore di premium una volta stipulato un contratto
*/

CREATE TRIGGER restore_premium
before update on streaming_film.contratto
for each row
	set new.premium = old.premium
	
/*
	Modifica i riferimenti ai clienti cancellati delle recensioni per mantenere le recensioni indicando un utente
	generico come relatore della recensione
*/

CREATE TRIGGER mantieni_recensione
before delete on streaming_film.cliente
for each row
	update streaming_film.recensioni
	set idcliente = 0
	where idcliente = old.idcliente;


/*
	Indica la data esatta della fine di un contratto non appena creato correggendo eventuali errori o dimenticanze.
*/

DELIMITER //

CREATE TRIGGER check_date
before insert on streaming_film.contratto
for each row
begin
	DECLARE n integer;
	select (new.datainizio + INTERVAL durata*30 DAY) into n
	from tipocontratto
	where idtipo = new.idtipo;
    
    set new.datafine = n;
end//

DELIMITER ;
	
/*
	Evita di eliminare un utente che è disattivato
*/

DELIMITER //

CREATE TRIGGER no_eliminazione_cliente_disattivato
before delete on streaming_film.cliente
for each row 
begin
	if old.disattivato = 1 THEN
    	SIGNAL sqlstate '45001' set message_text = "Il cliente selezionato è attualmente disattivo. Non è possibile cancellarlo senza la sua autorizzazione!";
    end if;
end//

DELIMITER ;
	
	
	
	