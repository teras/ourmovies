<?php

	require_once "layout.inc";

	layout_header($in_logout);

	echo $GLOBALS["in_goodbye"];

	layout_footer();
	session_destroy();

?>
