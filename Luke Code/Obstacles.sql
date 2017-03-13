BEGIN TRANSACTION;
CREATE TABLE Score(User_Score INT);
CREATE TABLE `Obstacles` (
	`id`	INTEGER NOT NULL,
	`name`	TEXT NOT NULL,
	`amount`	INTEGER NOT NULL,
	PRIMARY KEY(`id`)
);
INSERT INTO `Obstacles` VALUES (1,'Bomb',3);
INSERT INTO `Obstacles` VALUES (2,'Enemy Soldier',5);
CREATE TABLE `Effects` (
	`id_RK`	INTEGER NOT NULL,
	`description`	TEXT,
	`effect_value`	INTEGER NOT NULL,
	FOREIGN KEY(`id_RK`) REFERENCES Obstacles(id)
);
INSERT INTO `Effects` VALUES (1,'Kills/Resets Player',1);
INSERT INTO `Effects` VALUES (2,'Kills/Resets Player',2);
COMMIT;
