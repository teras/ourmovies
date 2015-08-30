#
# Table structure for table `movies`
#

DROP TABLE IF EXISTS movies;
CREATE TABLE movies (
  id int(8) NOT NULL auto_increment,
  local_name varchar(100) NOT NULL default '',
  inter_name varchar(100) NOT NULL default '',
  cds tinyint(1) NOT NULL default '0',
  type char(1) NOT NULL default '',
  imdbid varchar(50) default '',
  comment varchar(200) NOT NULL default '',
  PRIMARY KEY  (id),
  KEY id (id),
  KEY english_name (inter_name)
) TYPE=MyISAM;
# --------------------------------------------------------


#
# Table structure for table `type`
#

DROP TABLE IF EXISTS type;
CREATE TABLE type (
  typeid char(1) NOT NULL default '',
  name varchar(10) NOT NULL default '',
  icon varchar(50) NOT NULL default '',
  infourl varchar(100) default '',
  PRIMARY KEY  (typeid),
  UNIQUE KEY type (typeid)
) TYPE=MyISAM;
# --------------------------------------------------------


#
# Table structure for table `users`
#

DROP TABLE IF EXISTS users;
CREATE TABLE users (
  id int(8) NOT NULL auto_increment,
  sname varchar(40) NOT NULL default '',
  fname varchar(40) NOT NULL default '',
  username varchar(20) NOT NULL default '',
  pass varchar(20) NOT NULL default '',
  comment varchar(100) default NULL,
  PRIMARY KEY  (id),
  KEY username (username)
) TYPE=MyISAM;
# --------------------------------------------------------


#
# Table structure for table `whohaswhat`
#

DROP TABLE IF EXISTS whohaswhat;
CREATE TABLE whohaswhat (
  id int(8) NOT NULL auto_increment,
  diskid int(8) NOT NULL default '0',
  ownid int(8) NOT NULL default '0',
  PRIMARY KEY  (id)
) TYPE=MyISAM;


#
# Insert data
#

INSERT INTO users (id, sname, fname, username, pass, comment) VALUES (4, 'Administrator', 'Administrator', 'admin', 'aH.FjUfttZJok', 'Change the password of this user as soon as possible');

INSERT INTO type (typeid, name, icon, infourl) VALUES ('V', 'VideoCD', 'vcd.png', 'http://www.vcdhelp.com');
INSERT INTO type (typeid, name, icon, infourl) VALUES ('X', 'DivX', 'divx.png', 'http://www.divx.com');
INSERT INTO type (typeid, name, icon, infourl) VALUES ('D', 'DVD', 'dvd.png', 'http://www.dvdforum.org');
INSERT INTO type (typeid, name, icon, infourl) VALUES ('S', 'SVCD', 'svcd.png', 'http://www.vcdhelp.com/svcd.htm');

