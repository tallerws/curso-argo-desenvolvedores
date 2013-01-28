<?php

/**
 * @file
 * Provides callbacks for pages 
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
    //dpm($account, "Account na pagina de Top stalkers");
    $top = stalker_get_top_stalkers($account->uid);
    
    if($top){
       $items = array();
      foreach($top as $t){
          $items[] = theme("username", array("account" => user_load($t->uid))).": ".$t->view_counter;
      }  
      $content = theme("item_list", array("items" => $items));
    }else{
      $content = t("This user does not have top stalkers");  
    }
    return $content;
}
