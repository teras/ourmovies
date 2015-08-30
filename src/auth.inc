<?php

	require_once "lang.inc";
	require_once "layout.inc";
	require_once "server.inc";

	function auth_page ( $link, $tag_name ) {
		if ( $GLOBALS["session_is_auth"] != "yes" ) {
			layout_header($GLOBALS["in_authtitle"]);
			layout_header_message("in_authenticate");
			layout_auth($link, $tag_name);
			layout_footer();
			die();
		}
	}


	function author_user ( $username, $password ) {
		if ( $username == NULL || $username == "" ) return false;
		$salt_query = perform_query ( "SELECT LEFT(pass,2) FROM users WHERE username = '$username';" ) ;
		$salt = fetch_query_array ($salt_query);
		if ( ! $salt ) {
			return false;
		}
		$query = perform_query ("SELECT id FROM users WHERE username='$username' AND pass=ENCRYPT('$password', '" . $salt[0] . "') " );
		$uid = fetch_query_array ( $query );
		if ( $uid ) {
			$_SESSION["session_uid"]=$uid[0];
			return true;
		}
		return false;
	}

	function make_pass ( $pass) {
		$query = perform_query ( "SELECT ENCRYPT('$pass');" );
		$enpass = fetch_query_single_array ( $query );
		return $enpass[0];
	}

	if ( $session_is_auth != "yes" ) {
		if ( author_user ($auth_user, $auth_pass ) ) {
			$session_is_auth="yes";
		}
	}

?>
