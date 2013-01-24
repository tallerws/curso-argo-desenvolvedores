<?php

/**
 * @file
 * Provides callbacks and access handling for pages 
 * provided by the Stalker module
 */


/** 
 * Provides the Settings page for the Stalker module
 */
function stalker_configuration_page_callback(){
    return "OI!!!!";
}

/** 
 * Shows the top 5 stalker - the users who have seen the profile most time -
 * of the current profile being viewed
 */
function stalker_user_page_callback($account){
    dpm($account, "Account na pagina de Top stalkers");
    return "AQUI!";
}
