<?php

	$icon_view=true;

	function layout_header ($title) {
		generic_layout_header("", $title);
		echo "<table border=\"0\" width=\"100%\">\n";
		echo "<tr>\n<td valign=\"top\" width=\"20%\">\n";
		layout_main_menu();
		echo "<p>\n<a href=\"http://validator.w3.org/check/referer\"><img border=\"0\" src=\"http://www.w3.org/Icons/valid-html401\" alt=\"Valid HTML 4.01!\" height=\"31\" width=\"88\"></a>\n";
		echo "</td>\n<td valign=\"top\">\n";
	}

	function layout_footer () {
		echo "</td></tr>\n</table>\n\n";
		generic_layout_footer();
	}


	function layout_pre_movies () {
		$theme = array ("<table border=1>\n<tr><td align=\"center\">&nbsp;", "&nbsp;</td><td align=\"center\">&nbsp;", "&nbsp;</td><td align=\"center\">&nbsp;", "&nbsp;</td><td align=\"center\">&nbsp;", "&nbsp;</td></tr>\n");
		generic_layout_pre_movies ( $theme );
	}

	function layout_movie ( $count, $iname, $lname, $type, $id) {
		$theme = array ("<tr><td align=\"center\">&nbsp;", "&nbsp;</td><td>&nbsp;", "&nbsp;</td><td>&nbsp;", "&nbsp;</td><td align=\"center\">&nbsp;", "&nbsp;</td></tr>\n");
		generic_layout_movie ( $count, $iname, $lname, $type, $id, $theme );
	}

	function layout_post_movies () {
		echo  "</table>\n\n" ;
		generic_layout_post_movies();
	}

	function layout_movie_full ( $iname, $lname, $type, $cds, $comment, $users ) {
		$theme = array ( "<table border=1>\n<tr><td align=\"center\">&nbsp;", "&nbsp;</td><td align=\"center\">&nbsp;", "&nbsp;</td><td align=\"center\">&nbsp;", "</td><td align=\"center\">&nbsp;", "&nbsp;</td><td align=\"center\">&nbsp;", "&nbsp;</td></tr>\n<tr><td>&nbsp;", "&nbsp;</td><td>&nbsp;", "&nbsp;</td><td align=\"center\">&nbsp;", "&nbsp;</td><td align=\"center\">&nbsp;", "&nbsp;</td><td>&nbsp;", "&nbsp;</td></tr>\n</table>\n\n");
		generic_layout_movie_full ( $iname, $lname, $type, $cds, $comment, $users, $theme);
	}


	function layout_pre_users () {
		$theme = array ("<table border=1>\n<tr><td align=\"center\">&nbsp;", "&nbsp;</td><td align=\"center\">&nbsp;", "&nbsp;</td><td align=\"center\">&nbsp;", "&nbsp;</td></tr>\n");
		generic_layout_pre_users ( $theme );
	}

	function layout_user ( $count, $sname, $fname, $id) {
		$theme = array ("<tr><td align=\"center\">&nbsp;", "&nbsp;</td><td>&nbsp;", "&nbsp;</td><td>&nbsp;", "&nbsp;</td></tr>\n");
		generic_layout_user ( $count, $sname, $fname, $id, $theme );
	}

	function layout_post_users () {
		echo  "</table>\n\n" ;
		generic_layout_post_users();
	}

	function layout_user_full ( $sname, $fname, $uname, $comment, $cds) {
		$theme = array ( "<table border=1>\n<tr><td align=\"center\">&nbsp;", "&nbsp;</td><td align=\"center\">&nbsp;", "&nbsp;</td><td align=\"center\">&nbsp;", "&nbsp;</td><td align=\"center\">&nbsp;", "&nbsp;</td></tr>\n<tr><td>&nbsp;", "&nbsp;</td><td>&nbsp;", "&nbsp;</td><td>&nbsp;", "&nbsp;</td><td>&nbsp;", "&nbsp;</td></tr>\n</table>\n\n");
		generic_layout_user_full ( $sname, $fname, $uname, $comment, $cds, $theme);
	}

	function layout_edit_whw_pre_movies () {
		echo "<p>\n\n" . $GLOBALS["in_select_user_movies"] . "<br>\n";
		$theme = array ("<table border=1>\n<tr><td align=\"center\">&nbsp;", "&nbsp;</td><td align=\"center\">&nbsp;", "&nbsp;</td><td align=\"center\">&nbsp;", "&nbsp;</td><td align=\"center\">&nbsp;", "&nbsp;</td><td align=\"center\">&nbsp;", "&nbsp;</td></tr>\n");
		generic_layout_edit_whw_pre_movies ($theme) ;
	}

	function layout_edit_whw_movie ( $count, $iname, $lname, $type, $id, $hasit ) {
		$theme = array ( "<tr><td align=\"center\">&nbsp;", "&nbsp;</td><td>&nbsp;", "&nbsp;</td><td>&nbsp;", "&nbsp;</td><td align=\"center\">&nbsp;", "&nbsp;</td><td align=\"center\">&nbsp;", "&nbsp;</td></tr>\n");
		generic_layout_edit_whw_movie ( $count, $iname, $lname, $type, $id, $hasit, $theme );
	}

	function layout_edit_whw_post_movies () {
		echo  "</table>\n\n" ;
		generic_layout_edit_whw_post_movies () ;
	}




	function layout_edit_buttons ( $id, $owner ) {
		$theme = array ( "<table><tr>\n<td>\n", "</td>\n<td>\n", "</td>\n</tr></table>\n");
		generic_layout_edit_buttons ( $id, $owner, $theme );
	}


	function layout_edit_movie  ( $iname, $lname, $type, $cds, $comment, $users, $state, $id ) {
		$theme = array ( "border=0");
		generic_layout_edit_movie ( $iname, $lname, $type, $cds, $comment, $users, $state, $id, $theme );
	}

	function layout_edit_user_head  ( $sname, $fname, $comment, $state) {
		$theme = array ( "border=0");
		generic_layout_edit_user_head ( $sname, $fname, $comment, $state, $theme );
	}

	function layout_edit_user_tail ($min, $max, $state, $id) {
		generic_layout_edit_user_tail($min, $max, $state, $id);
	}

	function layout_header_message ( $message ) {
		$theme = array ("<h3>", "</h3>\n\n");
		generic_layout_header_message ( $message, $theme);
	}


	function layout_delete_button ($id, $owner, $state) {
		generic_layout_delete_button ( $id, $owner, $state);
	}



	function layout_display_type ($type) {
		generic_layout_display_type ( $type, $GLOBALS["icon_view"]);
	}

	function layout_display_cds ($cds) {
		generic_layout_display_cds ($cds, $GLOBALS["icon_view"]);
	}

	function layout_owner_list_head() {
		generic_layout_owner_list_head() ;
	}

	function layout_main_menu() {
		$theme = array ( "<table>\n<tr><td>", "</td></tr>\n<tr><td>", "</td></tr>\n<tr><td>", "</td></tr>\n<tr><td>", "</td></tr>\n<tr><td>", "</td></tr>\n<tr><td>", "</td></tr>\n</table>");
		generic_layout_main_menu ( $theme );
	}

	function layout_welcome () {
		echo "<h3>";
		generic_layout_welcome ();
		echo "</h3>";
	}

	function layout_options () {
		echo $ourmovies_theme;
		echo $ourmovies_lang;
		$theme = array ( "<table>\n<tr><td>", "</td><td>\n", "</td></tr>\n<tr><td>", "</td><td>\n", "</td></tr>\n</table>\n\n","");
		generic_layout_options ($theme);
	}

	function layout_auth($link, $tag_name) {
		$theme = array ( "<table>\n<tr><td>", "</td><td>\n", "</td></tr>\n<tr><td>", "</td><td>\n", "</td></tr>\n</table>\n\n","");
		generic_layout_auth($link, $tag_name, $theme);
	}

?>
