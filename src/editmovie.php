<?php
	require_once "server.inc";
	require_once "layout.inc";
	require_once "auth.inc";

	auth_page ( $GLOBALS["link_movie_edit"], "movieid" );

	layout_header($in_edit_movie);

	if ( $state == "edit" ) {
		 $query = perform_query ( "UPDATE movies SET inter_name='$inter_name', local_name='$local_name', cds='$cd_count', type='$cd_type', comment='$comment' WHERE id=$movieid;" );
		 layout_header_message("in_edit_updated");
	}
	elseif ( $state == "new" ) {
		$query = perform_query ( "INSERT INTO movies (inter_name, local_name, cds, type, comment) VALUES ('$inter_name', '$local_name', $cd_count, '$cd_type', '$comment');" );
		layout_header_message("in_new_updated");
		layout_movie_full ( $inter_name, $local_name, $cd_type, $cd_count, $comment, ""); 
	}
	elseif ( $movieid == "" ) {
		layout_header_message("in_new_movie");
		layout_edit_movie ( "", "", "", "", "", "", "new", "");
	}


	if ( $movieid != "" ) {
		layout_header_message("in_edit_movie");
		$query = perform_query ( "SELECT inter_name,local_name,type,cds,comment FROM movies WHERE id=$movieid;");
		$row = fetch_query_array ( $query );
		layout_edit_movie ( $row[0], $row[1], $row[2], $row[3], $row[4], "", "edit", $movieid );
	}

	layout_footer();
?>
