<?php

	$icon_view=true;
	$tablecol[0]="#ccccff";
	$tablecol[1]="#bbbbff";
	$tablecol[2]="#eeeeee";
	$tablecol[3]="#dddddd";


	function layout_header ($title) {
		generic_layout_header("<link rel=stylesheet type=\"text/css\" href=\"themes/colourfull.css\">\n", $title);
		echo "<table border=\"0\" cellspacing=\"0\" cellpadding=\"0\" width=\"100%\">\n";
		echo "<tr>\n<td valign=\"top\" width=\"20%\">\n";
		layout_main_menu();
		echo "<p>\n<a href=\"http://validator.w3.org/check/referer\"><img border=\"0\" src=\"http://www.w3.org/Icons/valid-html401\" alt=\"Valid HTML 4.01!\" height=\"31\" width=\"88\"></a></p>\n";
		echo "</td>\n<td valign=\"top\">\n";
	}

	function layout_footer () {
		echo "</td></tr>\n</table>\n\n";
		generic_layout_footer();
	}


	function layout_pre_movies () {
		$theme = array ("<table border=\"0\" cellspacing=\"0\" cellpadding=\"0\">\n<tr><th align=\"center\">&nbsp;", "&nbsp;</th><th align=\"center\">&nbsp;", "&nbsp;</th><th align=\"center\">&nbsp;", "&nbsp;</th><th align=\"center\">&nbsp;", "&nbsp;</th></tr>\n");
		generic_layout_pre_movies ( $theme );
	}


	function layout_movie ( $count, $iname, $lname, $type, $id) {
		static $col=2;
		global $tablecol;
		$col=2-$col;
		$b1=$tablecol[$col];
		$b2=$tablecol[$col+1];
			
		$theme = array ("<tr><td align=\"center\" bgcolor=\"$b1\">&nbsp;", "&nbsp;</td><td bgcolor=\"$b2\">&nbsp;", "&nbsp;</td><td bgcolor=\"$b1\">&nbsp;", "&nbsp;</td><td align=\"center\" bgcolor=\"$b2\">&nbsp;", "&nbsp;</td></tr>\n");
		generic_layout_movie ( $count, $iname, $lname, $type, $id, $theme );
	}

	function layout_post_movies () {
		echo  "</table>\n\n" ;
		generic_layout_post_movies();
	}

	function layout_movie_full ( $iname, $lname, $type, $cds, $comment, $users ) {
		global $tablecol;
		$b1=$tablecol[0];
		$b2=$tablecol[2];
		$theme = array ( "<table border=\"0\" cellspacing=\"0\" cellpadding=\"0\">\n<tr><th align=\"center\">&nbsp;", "&nbsp;</th><th align=\"center\">&nbsp;", "&nbsp;</th><th align=\"center\">&nbsp;", "</th><th align=\"center\">&nbsp;", "&nbsp;</th><th align=\"center\">&nbsp;", "&nbsp;</th></tr>\n<tr><td bgcolor=\"$b1\">&nbsp;", "&nbsp;</td><td bgcolor=\"$b2\">&nbsp;", "&nbsp;</td><td align=\"center\" bgcolor=\"$b1\">&nbsp;", "&nbsp;</td><td align=\"center\" bgcolor=\"$b2\">&nbsp;", "&nbsp;</td><td bgcolor=\"$b1\">&nbsp;", "&nbsp;</td></tr>\n</table>\n\n");
		generic_layout_movie_full ( $iname, $lname, $type, $cds, $comment, $users, $theme);
	}


	function layout_pre_users () {
		$theme = array ("<table border=\"0\" cellspacing=\"0\" cellpadding=\"0\">\n<tr><th align=\"center\">&nbsp;", "&nbsp;</th><th align=\"center\">&nbsp;", "&nbsp;</th><th align=\"center\">&nbsp;", "&nbsp;</th></tr>\n");
		generic_layout_pre_users ( $theme );
	}

	function layout_user ( $count, $sname, $fname, $id) {
		static $col=2;
		global $tablecol;
		$col=2-$col;
		$b1=$tablecol[$col];
		$b2=$tablecol[$col+1];

		$theme = array ("<tr><td align=\"center\" bgcolor=\"$b1\">&nbsp;", "&nbsp;</td><td bgcolor=\"$b2\">&nbsp;", "&nbsp;</td><td bgcolor=\"$b1\">&nbsp;", "&nbsp;</td></tr>\n");
		generic_layout_user ( $count, $sname, $fname, $id, $theme );
	}

	function layout_post_users () {
		echo  "</table>\n\n" ;
		generic_layout_post_users();
	}

	function layout_user_full ( $sname, $fname, $uname, $comment, $cds) {
		global $tablecol;
		$b1=$tablecol[0];
		$b2=$tablecol[2];
		$theme = array ( "<table border=\"0\" cellspacing=\"0\" cellpadding=\"0\">\n<tr><th align=\"center\">&nbsp;", "&nbsp;</th><th align=\"center\">&nbsp;", "&nbsp;</th><th align=\"center\">&nbsp;", "&nbsp;</th><th align=\"center\">&nbsp;", "&nbsp;</th></tr>\n<tr><td bgcolor=\"$b1\">&nbsp;", "&nbsp;</td><td bgcolor=\"$b2\">&nbsp;", "&nbsp;</td><td bgcolor=\"$b1\">&nbsp;", "&nbsp;</td><td bgcolor=\"$b2\">&nbsp;", "&nbsp;</td></tr>\n</table>\n\n");
		generic_layout_user_full ( $sname, $fname, $uname, $comment, $cds, $theme);
	}

	function layout_edit_whw_pre_movies () {
		echo "<p>\n\n" . $GLOBALS["in_select_user_movies"] . "<br>\n";
		$theme = array ("<table border=\"0\" cellspacing=\"0\" cellpadding=\"0\">\n<tr><th align=\"center\">&nbsp;", "&nbsp;</th><th align=\"center\">&nbsp;", "&nbsp;</th><th align=\"center\">&nbsp;", "&nbsp;</th><th align=\"center\">&nbsp;", "&nbsp;</th><th align=\"center\">&nbsp;", "&nbsp;</th></tr>\n");
		generic_layout_edit_whw_pre_movies ($theme) ;
	}

	function layout_edit_whw_movie ( $count, $iname, $lname, $type, $id, $hasit ) {
		static $col=2;
		global $tablecol;
		$col=2-$col;
		$b1=$tablecol[$col];
		$b2=$tablecol[$col+1];

		$theme = array ( "<tr><td align=\"center\" bgcolor=\"$b1\">&nbsp;", "&nbsp;</td><td bgcolor=\"$b2\">&nbsp;", "&nbsp;</td><td bgcolor=\"$b1\">&nbsp;", "&nbsp;</td><td align=\"center\" bgcolor=\"$b2\">&nbsp;", "&nbsp;</td><td align=\"center\" bgcolor=\"$b1\">&nbsp;", "&nbsp;</td></tr>\n");
		generic_layout_edit_whw_movie ( $count, $iname, $lname, $type, $id, $hasit, $theme );
	}

	function layout_edit_whw_post_movies () {
		echo  "</table>\n\n" ;
		generic_layout_edit_whw_post_movies () ;
	}




	function layout_edit_buttons ( $id, $owner ) {
		$theme = array ( "<table border=\"0\" cellspacing=\"0\" cellpadding=\"5\"><tr>\n<td>\n", "</td>\n<td>\n", "</td>\n</tr></table>\n");
		generic_layout_edit_buttons ( $id, $owner, $theme );
	}


	function layout_edit_movie  ( $iname, $lname, $type, $cds, $comment, $users, $state, $id ) {
		$theme = array ( "border=\"0\" cellspacing=\"0\" cellpadding=\"5\"");
		generic_layout_edit_movie ( $iname, $lname, $type, $cds, $comment, $users, $state, $id, $theme );
	}

	function layout_edit_user_head  ( $sname, $fname, $comment, $state) {
		$theme = array ( "border=\"0\" cellspacing=\"0\" cellpadding=\"5\"");
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
		$theme = array ( "<table bgcolor=\"#1d40f2\" border=\"0\" cellspacing=\"0\" cellpadding=\"0\">\n<tr><td align=\"left\"><img src=\"images/uleft.png\" alt=\"\" width=\"38\" height=\"38\"></td><td align=\"right\"><img src=\"images/uright.png\" alt=\"\" width=\"38\" height=\"38\"></td></tr>\n<tr align=\"center\"><td colspan=\"2\">&nbsp;</td></tr>\n<tr align=\"center\"><td colspan=\"2\">&nbsp;", "&nbsp;</td></tr>\n<tr align=\"center\"><td colspan=\"2\">&nbsp;", "&nbsp;</td></tr>\n<tr align=\"center\"><td colspan=\"2\">&nbsp;", "&nbsp;</td></tr>\n<tr align=\"center\"><td colspan=\"2\">&nbsp;", "&nbsp;</td></tr>\n<tr align=\"center\"><td colspan=\"2\">&nbsp;", "&nbsp;</td></tr>\n<tr align=\"center\"><td colspan=\"2\">&nbsp;", "&nbsp;</td></tr>\n<tr align=\"center\"><td colspan=\"2\">&nbsp;", "&nbsp;</td></tr>\n<tr><td align=\"left\"><img src=\"images/bleft.png\" alt=\"\" width=\"38\" height=\"38\"></td><td align=\"right\"><img src=\"images/bright.png\" alt=\"\" width=\"38\" height=\"38\"></td></tr>\n</table>\n\n");
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
		$theme = array ( "<table border=\"0\" cellspacing=\"0\" cellpadding=\"5\">\n<tr><td>", "</td><td>\n", "</td></td>\n<tr><td>", "</td><td>\n", "</td></tr>\n</table>\n\n", "");
		generic_layout_options ($theme);
	}

	function layout_auth($link, $tag_name) {
		$theme = array ( "<table border=\"0\" cellspacing=\"0\" cellpadding=\"5\">\n<tr><td>", "</td><td>\n", "</td></tr>\n<tr><td>", "</td><td>\n", "</td></tr>\n</table>\n\n","");
		generic_layout_auth($link, $tag_name, $theme);
	}

?>
