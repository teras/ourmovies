<?php
	require_once "server.inc";
	require_once "layout.inc";


	if ( $id != "" ) {
		layout_header($in_show_movie);
		layout_header_message ( "in_show_movie");
		$query = perform_query ( "SELECT inter_name,local_name,type,cds,comment FROM movies WHERE id=$id;");
		$row = fetch_query_array ( $query );
		layout_movie_full ( $row[0], $row[1], $row[2], $row[3], $row[4], "", $id );

		layout_owner_list_head();
		$query = perform_query ( "SELECT ownid FROM whohaswhat WHERE diskid=$id;");
		$owners = fetch_query_single_array ( $query );
		if ( $owners != "") {
			$count=0;
			layout_pre_users ();
			for ( $i = 0 ; $i < sizeof($owners) ; $i++ ) {
				$count++;
				$query = perform_query ( "SELECT sname, fname, comment FROM users WHERE id=".$owners[$i].";");
				$row=fetch_query_array ( $query );
				layout_user ($count, $row[0], $row[1], $owners[$i]);
			}
			layout_post_users();
		}

	
		layout_edit_buttons ($id, "movie");

	}
	else {
		layout_header($in_all_movies);
		layout_header_message ("in_all_movies");
		layout_pre_movies ();
		$query = perform_query ("SELECT inter_name,local_name,type,id FROM movies ORDER BY type DESC, inter_name ");
		$count = 0;
		while( $row = fetch_query_array ( $query )) {
			$count++;
			layout_movie($count, $row[0], $row[1], $row[2], $row[3]);
		}
		layout_post_movies();
	}

	layout_footer();
?>
