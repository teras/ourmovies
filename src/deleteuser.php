<?php
	require_once "server.inc";
	require_once "layout.inc";
	require_once "auth.inc";

	auth_page ( $GLOBALS["link_user_delete"], "userid" );

	layout_header($in_deltitle_user);

	if ( $state == "confirmed" ) {
		$query = perform_query ( "DELETE FROM users WHERE id=$userid;" );
		layout_header_message ("in_user_delete_updated");
	}
	elseif ( $userid != "" ) {
		layout_header_message ("in_delete_user");
		$query = perform_query ( "SELECT sname,fname,username,comment FROM users WHERE id=$userid;");
		$row = fetch_query_array ( $query );
		layout_user_full ( $row[0], $row[1], $row[2], $row[3], ""); 
		layout_delete_button($userid, "user","confirmed");
	}
	else {
		layout_header_message ( "in_unknown_user" );
	}

	layout_footer();
?>
