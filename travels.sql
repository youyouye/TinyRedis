use travel;
create table if not exists travel_talk
(
	uid int auto_increment primary key,
	url varchar(300),
	description varchar(100),
	nickname varchar(20),
	sendid varchar(30),
	longitude double,
	latitude double,
	uptime datetime NULL DEFAULT CURRENT_TIMESTAMP 
)default charset=utf8;
create table if not exists travel_mood
(
	uid int auto_increment primary key,
	nickname varchar(20),
	sendid varchar(30),
	content varchar(300),
	approval int,
	comments int,
	uptime datetime NULL DEFAULT CURRENT_TIMESTAMP
)default charset=utf8;
create table if not exists travel_mood_pic
(
	uid int,
	picurl varchar(300)
)default charset=utf8;
create table if not exists travel_mood_comment
(
	uid int,
	comments varchar(100),
	comid varchar(30),
	comnickname varchar(20),
	committime datetime NULL DEFAULT CURRENT_TIMESTAMP 
)default charset=utf8;

create table if not exists user
(
	uid int auto_increment primary key,
	username varchar(30),
	password varchar(30),
	nickname varchar(50),
	mobilenumber varchar(30)
)