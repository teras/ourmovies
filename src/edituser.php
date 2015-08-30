<?php
	require_once "server.inc";
	require_once "layout.inc";
	require_once "auth.inc";
	require_once "checks.inc";

	auth_page ( $GLOBALS["link_user_edit"], "userid" );

	layout_header($in_edit_user);

	if ( $state == "edit" ) {
		if ( $userid != $_SESSION["session_uid"] ) {
			layout_header_message ("in_no_authority");
			die();
		}
		$uname = retrieve_username ($userid);
		check_user_data ( $sname, $fname, $uname, $passold, $passnew1, $passnew2 );
		if ( $passnew1 != "" ) {
			$pass = make_pass ( $passnew1 );
			if ( !author_user($uname, $passold) ) {
				layout_header_message ("in_pass_error");
				die();
			}
			$query = perform_query ( "UPDATE users SET pass='$pass' WHERE id='$userid';" );
		}

		$query = perform_query ( "UPDATE users SET sname='$sname', fname='$fname', comment='$comment' WHERE id='$userid';" );
		layout_header_message("in_user_edit_updated");
		
		$query = perform_query ( "DELETE FROM whohaswhat WHERE ownid=$userid;");
		for ( $i=$min; $i <= $max ; $i++ ) {
			$current="hasit" . $i;
			if ( $$current != "" ) {
				$query = perform_query ( "INSERT INTO whohaswhat (ownid, diskid) VALUES ( $userid, $i );" );
			}
		}
	}
	elseif ( $state == "new" ) {
		check_user_data ( $sname, $fname, $uname, $passold, $passnew1, $passnew2 );
		if ( check_user_exists ($uname) ){
			layout_header_message ( "in_user_exists" );
			die();
		}
		$pass = make_pass ( $passnew1 );

		$query = perform_query ( "INSERT INTO users (sname, fname, username, pass, comment) VALUES ('$sname', '$fname', '$uname', '$pass', '$comment');" );
		layout_header_message("in_user_new_updated");
		layout_user_full ( $sname, $fname, $uname, $comment, $cds);
	}
	elseif ( $userid == "" ) {
		layout_header_message("in_new_user");
		layout_edit_user_head ( "", "", "", "new");
		layout_edit_user_tail( "", "", "new", "");
	}


	if ( $userid != "" ) {
		if ( $userid != $_SESSION["session_uid"] ) {
			layout_header_message ("in_no_authority");
			die();
		}
		layout_header_message("in_edit_user");
		$query = perform_query ( "SELECT sname,fname,comment FROM users WHERE id=$userid;");
		$row = fetch_query_array ( $query );
		layout_edit_user_head ( $row[0], $row[1], $row[2], "");
		fetch_selectable_movies( "edit", $userid);
	}

	layout_footer();
?>
