<?php

	require_once "lang.inc";
	require_once "layout.inc";

	function null_entry ( $name, $data ) {
		if ( $data == NULL | $data == "" ) {
		$m = $GLOBALS["in_empty_field"] . ": " . $name;
			layout_header_message ( "in_empty_field" );
			echo ( $name );
			return true;
		}
		return false;
	}

	function check_user_data ( $sname, $fname, $uname, $passold, $passnew1, $passnew2 ) {
		if ( null_entry ( $GLOBALS["in_user_name"], $sname ) || null_entry ( $GLOBALS["in_user_fam_name"], $fname ) || null_entry ( $GLOBALS["in_user"], $uname ) ) {
			die();
		}
		if ( $passold != "" || $passnew1 != "" || $passnew2 != "" ) {
			if ( null_entry ( $GLOBALS["in_pass"], $passold ) || null_entry ( $GLOBALS["in_pass"], $passnew1 ) && null_entry ( $GLOBALS["in_pass"], $passnew2) ) {
				die();
			}
			if ( $passnew1 != $passnew2 || strlen($passnew1) < 4 ) {
				layout_header_message ( "in_pass_error" );
				die();
			}
		}
		
		if (	$uname=="root" ||
				$uname=="admin" ||
				$uname=="lp" ||
				$uname=="daemon" ||
				$uname=="bin" ||
				$uname=="sys" ||
				$uname=="games" ||
				$uname=="man" ||
				$uname=="mail" ||
				$uname=="news" ||
				$uname=="nobody" ||
				$uname=="guest" ||
				$uname=="sshd"  ||
				strlen($uname) < 4) {
			layout_header_message ( "in_username_error" );
			die();
		}
	}
	
	function check_user_exists ($uname) {
		$exists[] = fetch_query_single_array ( perform_query("SELECT id FROM users WHERE username='$uname';" ));
		if ( $exists[0] != "" ) {
			return true;
		}
		return false;
	}
?>
