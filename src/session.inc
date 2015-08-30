<?php

	session_start();

	// Control theme information
	if ( !session_is_registered ("session_theme")) {
		session_register ("session_theme");
		$session_theme = "colourfull";
	}
	if ( $set_new_theme!="") $session_theme = $set_new_theme;

	// Control language information
	if ( !session_is_registered ("session_lang")){
		session_register ("session_lang");
		$session_lang = "greek";
	}
	if ( $set_new_lang!="") $session_lang = $set_new_lang;

	// Control authentication
	if ( !session_is_registered ("session_is_auth")) {
		session_register ("session_is_auth");
		$session_is_auth = "";
	}

	// Control username id
	if ( !session_is_registered ("session_uid")) {
		session_register ("session_uid");
		$session_uid = "";
	}

?>
