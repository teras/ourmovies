<?php
	require_once "lang.inc";
	require_once "server.inc";
	require_once "linknames.inc";
	require_once "system.inc";


	function generic_layout_header ($extra_header, $title) {
		echo "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">\n";
		echo "<html>\n<head>\n";
		echo "<title>" . $GLOBALS["def_title"] . " - " . $title . "</title>\n";
		echo "$extra_header";
		echo "</head>\n<body>\n\n";
	}

	function generic_layout_footer () {
		echo "</body>\n</html>\n";
	}

	function generic_layout_pre_movies ($th) {
		echo $th[0] . $GLOBALS["in_counter"] . $th[1] . $GLOBALS["in_inter_name"];
		echo $th[2] . $GLOBALS["in_local_name"] . $th[3] . $GLOBALS ["in_type"] . $th[4];
	}

	function generic_layout_movie ( $count, $iname, $lname, $type, $id, $th ) {
		echo $th[0] . $count . $th[1];
		echo "<a href=\"" . $GLOBALS["link_show"] . "?id=$id\">&nbsp;$iname&nbsp;</a>";
		echo $th[2];
		echo "<a href=\"" . $GLOBALS["link_show"] . "?id=$id\">&nbsp;$lname&nbsp;</a>";
		echo $th[3];
		layout_display_type($type);
		echo $th[4];
	}

	function generic_layout_post_movies () {
		echo "<p>\n";
	}

	function generic_layout_pre_users ($th) {
		echo $th[0] . $GLOBALS["in_counter"] . $th[1] . $GLOBALS["in_user_name"];
		echo $th[2] . $GLOBALS["in_user_fam_name"] . $th[3];
	}

	function generic_layout_user ( $count, $sname, $fname, $id, $th ) {
		echo $th[0] . $count . $th[1];
		echo "<a href=\"" . $GLOBALS["link_user_show"] . "?id=$id\">&nbsp;$sname&nbsp;</a>";
		echo $th[2];
		echo "<a href=\"" . $GLOBALS["link_user_show"] . "?id=$id\">&nbsp;$fname&nbsp;</a>";
		echo $th[3];
	}

	function generic_layout_post_users () {
		echo "<p>\n";
	}




	function generic_layout_movie_full ( $iname, $lname, $type, $cds, $comment, $users, $th ) {
		echo $th[0] . $GLOBALS["in_inter_name"] . $th[1] . $GLOBALS["in_local_name"];
		echo $th[2] . $GLOBALS ["in_type"] . $th[3] . $GLOBALS["in_cd_count"];
		echo $th[4] . $GLOBALS["in_comment"] . $th[5] . $iname;
		echo $th[6] . $lname . $th[7];
		layout_display_type($type);
		echo $th[8];
		layout_display_cds($cds);
		echo $th[9] . $comment . "&nbsp;" . $th[10];
	}


	function generic_layout_user_full ( $sname, $fname, $uname, $comment, $cds, $th ) {
		echo $th[0] . $GLOBALS["in_user_name"] . $th[1] . $GLOBALS["in_user_fam_name"];
		echo $th[2] . $GLOBALS["in_user"] . $th[3];
		echo $GLOBALS["in_comment"] . $th[4];
		echo $sname . $th[5] . $fname . $th[6];
		echo $uname . $th[7] . $comment . $th[8];
	}

	function generic_layout_edit_buttons ( $id, $owner, $th) {
		echo $th[0];
		echo "\t<form name=\"edit_".$owner."\" method=\"post\" action=\"" . $GLOBALS["link_".$owner."_edit"] . "\" >\n";
		echo "\t\t<input type=\"submit\" value=\"" . $GLOBALS["in_edit_".$owner."_button"] . "\">\n";
		echo "\t\t<input type=\"hidden\" name=\"".$owner."id\" VALUE=\"$id\">\n";
		echo "\t</form>\n";
		echo $th[1];
		echo "\t<form name=\"delete_".$owner."\" method=\"post\" action=\"" . $GLOBALS["link_".$owner."_delete"] . "\" >\n";
		echo "\t\t<input type=\"submit\" value=\"" . $GLOBALS["in_delete_".$owner."_button"] . "\">\n";
		echo "\t\t<input type=\"hidden\" name=\"".$owner."id\" VALUE=\"$id\">\n";
		echo "\t</form>\n";
		echo $th[2];
	}


	function generic_layout_edit_movie  ( $iname, $lname, $type, $cds, $comment, $users, $state, $id, $th ) {
		echo "<form name=\"edit_movie\" method=\"post\" action=\"" . $GLOBALS["link_movie_edit"] . "\">\n";
		echo "<table " . $th[0] . ">\n";
		echo "<tr><td>";
		echo "\t" . $GLOBALS["in_inter_name"] . "\n";
		echo "</td><td>";
		echo "\t<input type=\"text\" name=\"inter_name\" value=\"$iname\">\n";
		echo "</td></tr>\n<tr><td>\n";
		echo "\t" . $GLOBALS["in_local_name"] . "\n";
		echo "</td><td>";
		echo "\t<input type=\"text\" name=\"local_name\" value=\"$lname\">\n";
		echo "</td></tr>\n<tr><td>\n";
		echo "\t" . $GLOBALS ["in_cd_count"] . "\n";
		echo "</td><td>\n";
		$disks = array ( "1", "2", "3", "4" );
		generic_form_select ( $disks, $disks, $cds, "cd_count");
		echo "</td></tr>\n<tr><td>\n";
		echo "\t" . $GLOBALS["in_type"] . "\n";
		echo "</td><td>";
		$typesid=fetch_query_single_array (perform_query("SELECT typeid FROM type ORDER BY typeid;"));
		$typesname=fetch_query_single_array (perform_query("SELECT name FROM type ORDER BY typeid;"));
		generic_form_select ( $typesid, $typesname, $type, "cd_type");
		echo "</td></tr>\n<tr><td>\n";
		echo "\t" . $GLOBALS["in_comment"] . "\n";
		echo "</td><td>";
		echo "\t<input type=\"text\" name=\"comment\" value=\"$comment\">\n";
		echo "</td></tr>\n</table>\n\n";
		echo "<input type=\"submit\" value=\"" . $GLOBALS["in_confirm_button"] . "\">\n";
		echo "<input type=\"hidden\" name=\"state\" VALUE=\"$state\">\n";
		echo "<input type=\"hidden\" name=\"movieid\" VALUE=\"$id\">\n";
		echo "</form>\n\n";
	}


	function generic_layout_edit_user_head  ( $sname, $fname, $comment, $state, $th ) {
		echo "<form name=\"edit_user\" method=\"post\" action=\"" . $GLOBALS["link_user_edit"] . "\">\n";
		echo "<table " . $th[0] . ">\n";
		echo "<tr><td>";
		echo "\t" . $GLOBALS["in_user_name"] . "\n";
		echo "</td><td>";
		echo "\t<input type=\"text\" name=\"sname\" value=\"$sname\">\n";
		echo "</td></tr>\n<tr><td>\n";
		echo "\t" . $GLOBALS["in_user_fam_name"] . "\n";
		echo "</td><td>";
		echo "\t<input type=\"text\" name=\"fname\" value=\"$fname\">\n";
		echo "</td></tr>\n<tr><td>\n";
		echo "\t" . $GLOBALS["in_comment"] . "\n";
		echo "</td><td>";
		echo "\t<input type=\"text\" name=\"comment\" value=\"$comment\">\n";
		echo "</td></tr>\n<tr><td>\n";
		if ( $state != "new" ){
			echo "\t" . $GLOBALS["in_pass"] . " ( " . $GLOBALS["in_old"] . " ) \n";
			echo "</td><td>";
			echo "<input type=\"password\" name=\"passold\" value=\"\">\n" . $th[4];
			echo "</td></tr>\n<tr><td>\n";
		}
		else {
			echo "\t" . $GLOBALS["in_user"] . " \n";
			echo "</td><td>";
			echo "<input type=\"text\" name=\"uname\" value=\"\">\n" . $th[4];
			echo "</td></tr>\n<tr><td>\n";
		}
		echo "\t" . $GLOBALS["in_pass"] . " ( " . $GLOBALS["in_new"] . " ) \n";
		echo "</td><td>";
		echo "<input type=\"password\" name=\"passnew1\" value=\"\">\n" . $th[4];
		echo "</td></tr>\n<tr><td>\n";
		echo "\t" . $GLOBALS["in_pass"] . " ( " . $GLOBALS["in_new"] . " - " . $GLOBALS["in_as_above"] ." ) \n";
		echo "</td><td>";
		echo "<input type=\"password\" name=\"passnew2\" value=\"\">\n" . $th[4];
		echo "</td></tr>\n";
		echo "</table>\n\n";
	}

	function generic_layout_edit_user_tail($min, $max, $state, $id) {
		echo "<input type=\"submit\" value=\"" . $GLOBALS["in_confirm_button"] . "\">\n";
		echo "<input type=\"hidden\" name=\"min\" VALUE=\"$min\">\n";
		echo "<input type=\"hidden\" name=\"max\" VALUE=\"$max\">\n";
		echo "<input type=\"hidden\" name=\"state\" VALUE=\"$state\">\n";
		echo "<input type=\"hidden\" name=\"userid\" VALUE=\"$id\">\n";
		echo "</form>\n\n";
	}

	function generic_layout_header_message ( $message, $th ) {
		echo $th[0] . $GLOBALS["$message"] . $th[1];
	}


	function generic_layout_delete_button ($id, $owner, $state) {
		echo "<form name=\"".$owner."_movie\" method=\"post\" action=\"" . $GLOBALS["link_".$owner."_delete"] . "\">\n";
		echo "<input type=\"hidden\" name=\"".$owner."id\" VALUE=\"$id\">\n";
		echo "<input type=\"hidden\" name=\"state\" VALUE=\"$state\">\n";
		echo "<input type=\"submit\" value=\"" . $GLOBALS["in_confirm_button"] . "\">\n";
		echo "</form>";
	}


// Helper Functions for this theme

	function generic_form_select ( $name_list, $show_list, $default, $name ) {
		echo "\t<select name=\"$name\">\n";
		for ( $i=0 ; $i < sizeof($show_list) ; $i++ ) {
			echo "\t\t<option value=\"" . $name_list[$i] . "\"";
			if ( $default==$name_list[$i] ) {
				echo " selected";
			}
			echo ">" . $show_list[$i] . "</option>\n";
		}
		echo "\t</select>\n";
	}


function generic_layout_display_type ($type, $icon) {
		$query = perform_query ("SELECT icon,name,infourl FROM type WHERE typeid='$type';"); 
		$row = fetch_query_array ( $query );
		echo "<a href=\"" . $row[2] . "\">";
		if ( $icon==true ) {
			echo "<img src=\"" . $GLOBALS["link_images"] . $row[0] . "\" alt=\"" . $row[1] . "\" border=\"0\" >";
		}
		else {
			echo $row[1];
		}
		echo "</a>";
	}


	function generic_layout_display_cds ($cds, $icon) {
		if ( $icon==true ) {
			echo "<img src=\"" . $GLOBALS["link_images"] ."cd" . $cds . ".png\" alt=\"" . $cds . "\" border=\"0\" >";
		}
		else {
			echo $cds;
		}
	}


	function generic_layout_edit_whw_pre_movies ($th) {
		echo $th[0] . $GLOBALS["in_counter"] . $th[1] . $GLOBALS["in_inter_name"];
		echo $th[2] . $GLOBALS["in_local_name"] . $th[3];
		echo $GLOBALS["in_type"] . $th[4] . "&nbsp;" . $th[5];
	}

	function generic_layout_edit_whw_movie ($count, $iname, $lname, $type, $id, $hasit, $th) {
		echo $th[0] . $count . $th[1];
		echo $iname . $th[2]. $lname . $th[3];
		layout_display_type($type);
		echo $th[4];
		echo "<input type=\"checkbox\" name=\"hasit$id\"";
		if ( $hasit) echo " checked";
		echo ">" . $th[5];
	}

	function generic_layout_edit_whw_post_movies () {
		echo "<p>\n";
	}


	function generic_layout_owner_list_head() {
		echo "<p>\n";
	}

	function generic_layout_main_menu ($th) {
		echo $th[0];
		echo "<a class=\"menu\" href=\"".$GLOBALS["link_home"]."\">";
		echo $GLOBALS["in_home_page"];
		echo "</a>";
		echo $th[1];
		echo "<a class=\"menu\" href=\"".$GLOBALS["link_show"]."\">".$GLOBALS["in_all_movies"]."</a>";
		echo $th[2];
		echo "<a class=\"menu\" href=\"".$GLOBALS["link_user_show"]."\">".$GLOBALS["in_all_users"]."</a>";
		echo $th[3];
		echo "<a class=\"menu\" href=\"".$GLOBALS["link_movie_edit"]."\">".$GLOBALS["in_new_movie"]."</a>";
		echo $th[4];
		echo "<a class=\"menu\" href=\"".$GLOBALS["link_user_edit"]."\">".$GLOBALS["in_new_user"]."</a>";
		echo $th[5];
		echo "<a class=\"menu\" href=\"".$GLOBALS["link_options"]."\">".$GLOBALS["in_options"]."</a>";
		echo $th[6];
		echo "<a class=\"menu\" href=\"".$GLOBALS["link_logout"]."\">".$GLOBALS["in_logout"]."</a>";
		echo $th[7];
	}

	function generic_layout_welcome () {
		echo $GLOBALS["in_welcome"];
	}

	function generic_layout_options ($th) {
		$theme_list = find_themes();
		$lang_list = find_languages();

		echo $th[0];
		echo "\t<form name=\"options\" method=\"post\" action=\"".$GLOBALS["link_options"]."\" >\n";
		echo $GLOBALS["in_opt_theme"] . $th[1];
		generic_form_select ( $theme_list, $theme_list, $GLOBALS["session_theme"], "set_new_theme" );
		echo $th[2] . $GLOBALS["in_opt_lang"] . $th[3];
		generic_form_select ( $lang_list, $lang_list, $GLOBALS["session_lang"], "set_new_lang" );
		echo $th[4];
		echo "<input type=\"submit\" value=\"" . $GLOBALS["in_confirm_button"] . "\">\n";
		echo "</form>\n\n";
		echo $th[5];

	}

	function generic_layout_auth($link, $tag_name, $th) {
		echo $th[0] . "<form name=\"auth\" method=\"post\" action=\"$link\" >\n";
		echo $GLOBALS["in_auth_user"] . $th[1];
		echo "<input type=\"text\" name=\"auth_user\" value=\"\">\n" . $th[2];
		echo $GLOBALS["in_auth_pass"] . $th[3];
		echo "<input type=\"password\" name=\"auth_pass\" value=\"\">\n" . $th[4];
		echo "<input type=\"submit\" value=\"" . $GLOBALS["in_confirm_button"] . "\">\n";
		echo "<input type=\"hidden\" name=\"$tag_name\" value=\"" . $GLOBALS["$tag_name"] . "\">\n";
		echo "</form>\n\n";
		echo $th[5];
	}

?>
