CREATE TABLE IF NOT EXISTS `db`.`user` (
    `id` INT NOT NULL AUTO_INCREMENT,
    `name` CHAR(255) NOT NULL,
    `email` CHAR(255) NOT NULL,
    `password` CHAR(255) NOT NULL,
    PRIMARY KEY (`id`)
) ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS `verif_code` (
  `user_id` int NOT NULL,
  `code` char(6) NOT NULL
) ENGINE=InnoDB;

CREATE TABLE IF NOT EXISTS `auto_login` (
  `user_id` int NOT NULL,
  `token` char(36) NOT NULL
) ENGINE=InnoDB;

CREATE TABLE IF NOT EXISTS `dashboard` (
  `user_id` int NOT NULL,
  `dashboard` text NOT NULL,
  PRIMARY KEY (`user_id`)
) ENGINE=InnoDB;

CREATE TABLE IF NOT EXISTS `tokens` (
  `user_id` int NOT NULL,
  `tokens` text NOT NULL,
  PRIMARY KEY (`user_id`)
) ENGINE=InnoDB;