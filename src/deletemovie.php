<?php
	require_once "server.inc";
	require_once "layout.inc";
	require_once "auth.inc";

	auth_page ( $GLOBALS["link_movie_delete"], "movieid" );
	
	layout_header($in_deltitle_movie);

	if ( $state == "confirmed" ) {
		$query = perform_query ( "DELETE FROM movies WHERE id=$movieid;" );
		layout_header_message ("in_delete_updated");
	}
	elseif ( $movieid != "" ) {
		layout_header_message ("in_delete_movie");
		$query = perform_query ( "SELECT inter_name,local_name,type,cds,comment FROM movies WHERE id=$movieid;");
		$row = fetch_query_array ( $query );
		layout_movie_full ( $row[0], $row[1], $row[2], $row[3], $row[4], ""); 
		layout_delete_button($movieid, "movie", "confirmed");
	}
	else {
		layout_header_message ( "in_unknown_movie" );
	}

	layout_footer();
?>
