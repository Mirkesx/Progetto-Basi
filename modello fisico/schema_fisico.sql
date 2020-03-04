-- MySQL Script generated by MySQL Workbench
-- Sun Sep 22 11:46:06 2019
-- Model: New Model    Version: 1.0
-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema streaming_film
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema streaming_film
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `streaming_film` DEFAULT CHARACTER SET utf8 ;
USE `streaming_film` ;

-- -----------------------------------------------------
-- Table `streaming_film`.`Artista`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `streaming_film`.`Artista` (
  `idartista` INT NOT NULL AUTO_INCREMENT,
  `nome` VARCHAR(45) NOT NULL,
  `cognome` VARCHAR(45) NOT NULL,
  `nazionalità` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`idartista`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `streaming_film`.`Film`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `streaming_film`.`Film` (
  `idfilm` INT NOT NULL AUTO_INCREMENT,
  `titolo` VARCHAR(45) NOT NULL,
  `durata` VARCHAR(45) NOT NULL,
  `annoprod` VARCHAR(45) NOT NULL,
  `datapub` VARCHAR(45) NOT NULL,
  `trama` VARCHAR(512) NOT NULL,
  `n_recensioni` INT NULL,
  `mediarating` DOUBLE NULL,
  `idregista` INT NOT NULL,
  `lingua` VARCHAR(45) NULL,
  `sottotitoli` TINYINT NULL,
  PRIMARY KEY (`idfilm`),
  INDEX `fk_Film_Artista1_idx` (`idregista` ASC) VISIBLE,
  CONSTRAINT `fk_Film_Artista1`
    FOREIGN KEY (`idregista`)
    REFERENCES `streaming_film`.`Artista` (`idartista`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `streaming_film`.`AttoreFilm`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `streaming_film`.`AttoreFilm` (
  `idattore` INT NOT NULL,
  `idfilm` INT NOT NULL,
  INDEX `fk_AttoreFilm_Artista_idx` (`idattore` ASC) VISIBLE,
  INDEX `fk_AttoreFilm_Film1_idx` (`idfilm` ASC) VISIBLE,
  PRIMARY KEY (`idattore`, `idfilm`),
  CONSTRAINT `fk_AttoreFilm_Artista`
    FOREIGN KEY (`idattore`)
    REFERENCES `streaming_film`.`Artista` (`idartista`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_AttoreFilm_Film1`
    FOREIGN KEY (`idfilm`)
    REFERENCES `streaming_film`.`Film` (`idfilm`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `streaming_film`.`Genere`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `streaming_film`.`Genere` (
  `idgenere` INT NOT NULL AUTO_INCREMENT,
  `nome` VARCHAR(45) NULL,
  PRIMARY KEY (`idgenere`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `streaming_film`.`GenereFilm`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `streaming_film`.`GenereFilm` (
  `idfilm` INT NOT NULL,
  `idgenere` INT NOT NULL,
  INDEX `fk_GenereFilm_Film1_idx` (`idfilm` ASC) VISIBLE,
  INDEX `fk_GenereFilm_Genere1_idx` (`idgenere` ASC) VISIBLE,
  PRIMARY KEY (`idfilm`, `idgenere`),
  CONSTRAINT `fk_GenereFilm_Film1`
    FOREIGN KEY (`idfilm`)
    REFERENCES `streaming_film`.`Film` (`idfilm`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_GenereFilm_Genere1`
    FOREIGN KEY (`idgenere`)
    REFERENCES `streaming_film`.`Genere` (`idgenere`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `streaming_film`.`Cliente`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `streaming_film`.`Cliente` (
  `idcliente` INT NOT NULL AUTO_INCREMENT,
  `nickname` VARCHAR(45) NOT NULL,
  `nome` VARCHAR(45) NOT NULL,
  `cognome` VARCHAR(45) NOT NULL,
  `datanascita` DATE NOT NULL,
  `email` VARCHAR(45) NOT NULL,
  `indirizzo` VARCHAR(45) NULL,
  `telefono` VARCHAR(12) NULL,
  `genere` VARCHAR(10) NULL,
  PRIMARY KEY (`idcliente`),
  UNIQUE INDEX `nickname_UNIQUE` (`nickname` ASC) VISIBLE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `streaming_film`.`Recensioni`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `streaming_film`.`Recensioni` (
  `idcliente` INT NOT NULL,
  `idfilm` INT NOT NULL,
  `descrizione` VARCHAR(256) NOT NULL,
  `rating` DOUBLE NOT NULL,
  INDEX `fk_Recensioni_Cliente1_idx` (`idcliente` ASC) VISIBLE,
  INDEX `fk_Recensioni_Film1_idx` (`idfilm` ASC) VISIBLE,
  PRIMARY KEY (`idcliente`, `idfilm`),
  CONSTRAINT `fk_Recensioni_Cliente1`
    FOREIGN KEY (`idcliente`)
    REFERENCES `streaming_film`.`Cliente` (`idcliente`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Recensioni_Film1`
    FOREIGN KEY (`idfilm`)
    REFERENCES `streaming_film`.`Film` (`idfilm`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `streaming_film`.`TipoContratto`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `streaming_film`.`TipoContratto` (
  `idtipo` INT NOT NULL,
  `durata` INT NOT NULL,
  `costo` INT NOT NULL,
  `nomecontratto` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`idtipo`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `streaming_film`.`Contratto`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `streaming_film`.`Contratto` (
  `idcontratto` INT NOT NULL,
  `datainizio` DATE NOT NULL,
  `datafine` DATE NOT NULL,
  `premium` TINYINT NULL DEFAULT 0,
  `idtipo` INT NOT NULL,
  `idcliente` INT NOT NULL,
  PRIMARY KEY (`idcontratto`),
  INDEX `fk_Contratto_TipoContratto1_idx` (`idtipo` ASC) VISIBLE,
  INDEX `fk_Contratto_Cliente1_idx` (`idcliente` ASC) VISIBLE,
  CONSTRAINT `fk_Contratto_TipoContratto1`
    FOREIGN KEY (`idtipo`)
    REFERENCES `streaming_film`.`TipoContratto` (`idtipo`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Contratto_Cliente1`
    FOREIGN KEY (`idcliente`)
    REFERENCES `streaming_film`.`Cliente` (`idcliente`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
