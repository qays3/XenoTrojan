CREATE TABLE `victim` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `ip` varchar(45) NOT NULL,
  `timestamp_column` timestamp NOT NULL DEFAULT current_timestamp(),
  PRIMARY KEY (`id`)
) 
