<?php

	require_once "layout.inc";
	require_once "config.inc";


	$mysqlserver = mysql_pconnect ($sql_server, $sql_username, $sql_password)
		or die ( "Could not connect to database:" . mysql_error());

	$database = mysql_select_db ("ourmovies")
		or die (" Could not select database ourmovies: " . mysql_error());

	function perform_query ($query) {
		$res = mysql_query ( $query ) or die ( "Could not perform query \"$query\": " .  mysql_error());
		return $res;
	}

	function fetch_query_array ($query) {
		$res = mysql_fetch_array ( $query );
		return $res;
	}

	function fetch_query_single_array ($query) {
		$res="";
		while ( $line=mysql_fetch_array ($query)) {
			$res[]=$line[0];
		}
		return $res;
	}

	function fetch_selectable_movies($state, $userid) {
		$query = perform_query ( "SELECT inter_name,local_name,type,id FROM movies ORDER BY type DESC, inter_name;");
		$count=0;
		$min=-1;
		$max=-1;
		layout_edit_whw_pre_movies();
		while  ( $row = fetch_query_array ($query)) {
			$count++;
			if ( $min < 0 ) $min = $row[3];
			if ( $min > $row[3] ) $min = $row[3];
			if ( $max < $row[3] ) $max = $row[3];
			$hasquery = perform_query ( "SELECT ownid FROM whohaswhat WHERE diskid=" . $row[3] . " AND ownid=$userid;" );
			if ( fetch_query_array ( $hasquery ) ) $hasit=true;
			layout_edit_whw_movie ( $count, $row[0], $row[1], $row[2], $row[3], $hasit );
			$hasit=false;
		}
		layout_edit_whw_post_movies();
		layout_edit_user_tail($min, $max, $state, $userid);
	}

	function retrieve_username ( $id ) {
		$user = fetch_query_single_array ( perform_query ( "SELECT username FROM users WHERE id='$id';") );
		return $user[0];
	}

?>
