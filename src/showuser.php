<?php
	require_once "server.inc";
	require_once "layout.inc";


	if ( $id != "" ) {
		layout_header($in_show_user);
		layout_header_message ( "in_show_user");
		$query = perform_query ( "SELECT sname,fname,username,comment,id FROM users WHERE id=$id;");
		$row = fetch_query_array ( $query );
		layout_user_full ( $row[0], $row[1], $row[2], $row[3], "");

		layout_owner_list_head();
		$query = perform_query ( "SELECT diskid FROM whohaswhat,movies WHERE ownid=$id AND diskid=movies.id ORDER BY type DESC, inter_name;");
		$disks = fetch_query_single_array ( $query );
		if ( $disks != "") {
			$count=0;
			layout_pre_movies ();
			for ( $i = 0 ; $i < sizeof($disks) ; $i++ ) {
				$count++;
				$query = perform_query ( "SELECT inter_name,local_name,type FROM movies WHERE id=".$disks[$i].";");
				$row=fetch_query_array ( $query );
				layout_movie ($count, $row[0], $row[1], $row[2], $disks[$i]);
			}
			layout_post_movies();
		}
		
		layout_edit_buttons ($id, "user");
	}
	else {
		layout_header($in_all_users);
		layout_header_message ("in_all_users");
		layout_pre_users ();
		$query = perform_query ("SELECT sname,fname,id FROM users ORDER BY fname, sname;");
		$count = 0;
		while( $row = fetch_query_array ( $query )) {
			$count++;
			layout_user($count, $row[0], $row[1], $row[2]);
		}
		layout_post_users();
	}

	layout_footer();
?>
