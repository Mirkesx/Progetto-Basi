DELIMITER $$
CREATE PROCEDURE crea_nuovi_contratti ()
BEGIN
    DECLARE finished INTEGER DEFAULT 0;
    DECLARE idc integer DEFAULT 0;
	DECLARE idt integer DEFAULT 0;
	DECLARE n integer;
    DECLARE m integer;
 
    -- cursore per clienti premium e non
    DEClARE curClientiP
        CURSOR FOR 
            SELECT idcliente, idtipo FROM contratto where premium = 1 && datafine = date(now());
			
	DEClARE curClienti
        CURSOR FOR 
            SELECT idcliente, idtipo FROM contratto where premium = 0 && datafine = date(now());
 
    -- declare NOT FOUND handler
    DECLARE CONTINUE HANDLER 
        FOR NOT FOUND SET finished = 1;
		
	select count(*) into n
    from contratto;
 
    OPEN curClientiP;
 
    clientiP: LOOP
        FETCH curClientiP INTO idc, idt;
        IF finished = 1 THEN 
            LEAVE clientiP;
        END IF;
        -- crea un nuovo record
        insert into contratto(datainizio,datafine,premium,idcliente,idtipo)
		values (date(now()),date(now()),1,idc,idt);
    END LOOP clientiP;
	
	CLOSE curClientiP;
	
	OPEN curClienti;
	
	clientiP: LOOP
        FETCH curClienti INTO idc, idt;
        IF finished = 1 THEN 
            LEAVE clientiP;
        END IF;
        -- crea un nuovo record
        insert into contratto(datainizio,datafine,premium,idcliente,idtipo)
		values (date(now()),date(now()),0,idc,idt);
    END LOOP clientiP;
	
    CLOSE curClienti;
	
	select count(*) into m
    from contratto;
	
	insert into event_log (contratti_prima,contratti_dopo)
    values(n,m);
 
END$$
DELIMITER ;
