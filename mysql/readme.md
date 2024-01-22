CREATE DATABASE carReserve; 
use carReserve;

show tables;

CREATE TABLE `Doors` (
  `DoorID` int NOT NULL,
  `DoorName` varchar(10) DEFAULT NULL,
  PRIMARY KEY (`DoorID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

INSERT INTO `Doors` VALUES (1,'南一门'),(2,'南二门'),(3,'南三门');

select * from vehicle;

SELECT * FROM reserve
WHERE TIMESTAMP > NOW() - INTERVAL 2 minute;

select * from reserve;
select * from each_reserve;
SELECT staff_name, department FROM staff WHERE staff_no = 'M202373903';
CREATE TABLE `staff` (
  `staff_name` varchar(20) NOT NULL,
  `staff_no` varchar(10) NOT NULL,
  `campus` enum('main','tongji') NOT NULL DEFAULT 'main',
  `staff_id` varchar(20) NOT NULL,
  PRIMARY KEY (`staff_no`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

ALTER TABLE `staff`
ADD COLUMN `department` varchar(20) NOT NULL AFTER `staff_id`;

INSERT INTO `staff` VALUES ('汪睿','M202373903','main','123456200301061234','网络与计算中心'),('小红','12346','tongji','412100200301060021','软件学院');
CREATE TABLE `vehicle` (
  `vehicle_id` varchar(20) NOT NULL,
  `owner_id` varchar(20) NOT NULL,
  `isinside` enum('inside','outside') NOT NULL DEFAULT 'outside',
  PRIMARY KEY (`vehicle_id`)
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf8mb3;
CREATE TABLE `visitor` (
  `visitor_name` varchar(15) NOT NULL,
  `visitor_id` varchar(20) NOT NULL,
  `visitor_phone` varchar(11) DEFAULT NULL,
  PRIMARY KEY (`visitor_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
SELECT * FROM vehicle;
CREATE TABLE `ParkingFee` (
  `FeeID` int NOT NULL AUTO_INCREMENT,
  `VehicleID` varchar(20) DEFAULT NULL,
  `EntryTime` datetime DEFAULT NULL,
  `ExitTime` datetime DEFAULT NULL,
  `FeeAmount` int DEFAULT NULL,
  `PayWay` enum('cash','wechat','alipay') DEFAULT NULL,
  `VehicleType` enum('Internal','Visitor','Registered') NOT NULL,
  PRIMARY KEY (`FeeID`)
) ENGINE=InnoDB AUTO_INCREMENT=35 DEFAULT CHARSET=utf8mb3;
SELECT COUNT(*) FROM vehicle WHERE vehicle_id='鄂A12345';
CREATE TABLE `each_reserve` (
  `reserve_id` int NOT NULL,
  `visitor_id` varchar(20) NOT NULL,
  PRIMARY KEY (`reserve_id`,`visitor_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

CREATE TABLE `reserve` (
  `reserve_id` int NOT NULL AUTO_INCREMENT,
  `staff_no` varchar(10) NOT NULL,
  `date` datetime NOT NULL,
  `way` enum('walk','drive') NOT NULL DEFAULT 'walk',
  `cause` enum('official','personal') NOT NULL DEFAULT 'official',
  `vehicle_id` varchar(20) DEFAULT NULL,
  `visitor_id` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`reserve_id`)
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf8mb3;
ALTER TABLE `reserve`
ADD COLUMN `visitor_name` varchar(20) NOT NULL AFTER `visitor_id`;
-- 默认值为当前时间，更新时更新为当前时间
ALTER TABLE reserve
ADD COLUMN timestamp TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP;

CREATE TABLE `AccessHistory` (
  `AccessID` int NOT NULL AUTO_INCREMENT,
  `VehicleID` varchar(20) DEFAULT NULL,
  `EntryDoorID` int DEFAULT NULL,
  `ExitDoorID` int DEFAULT NULL,
  `EntryTime` datetime DEFAULT NULL,
  `ExitTime` datetime DEFAULT NULL,
  PRIMARY KEY (`AccessID`),
  KEY `EntryDoorID` (`EntryDoorID`),
  KEY `ExitDoorID` (`ExitDoorID`),
  CONSTRAINT `AccessHistory_ibfk_1` FOREIGN KEY (`EntryDoorID`) REFERENCES `Doors` (`DoorID`),
  CONSTRAINT `AccessHistory_ibfk_2` FOREIGN KEY (`ExitDoorID`) REFERENCES `Doors` (`DoorID`)
) ENGINE=InnoDB AUTO_INCREMENT=40 DEFAULT CHARSET=utf8mb3;


create table `ManageMember`(
	user_id INT AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(255) NOT NULL,
    password VARCHAR(255) NOT NULL,
    name varchar(255) not null,
    phone varchar(255) not null,
    email varchar(255),
    role varchar(50) not null
)ENGINE=InnoDB AUTO_INCREMENT=40 DEFAULT CHARSET=utf8mb3;

select * from ManageMember;
select password from ManageMember where username='wr';

select * from reserve where reserve.staff_no in (select staff_no from staff where department='软件学院');

CREATE DATABASE auditor; 
use auditor;
show tables;
select * from ManageMember;
CREATE TABLE `staff` (
  `staff_name` varchar(20) NOT NULL,
  `staff_no` varchar(10) NOT NULL,
  `campus` enum('main','tongji') NOT NULL DEFAULT 'main',
  `staff_id` varchar(20) NOT NULL,
  `department` varchar(20) NOT NULL,
  PRIMARY KEY (`staff_no`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
INSERT INTO `staff` VALUES ('汪睿','M202373903','main','123456200301061234','网络与计算中心'),('小红','12346','tongji','412100200301060021','软件学院');

drop table vehicle;
