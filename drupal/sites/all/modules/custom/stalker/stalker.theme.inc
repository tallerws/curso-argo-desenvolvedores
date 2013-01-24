<?php

/**
 * @file 
 * File which contains all of theme function 
 * and themable output provided by the stalker module
 */

/**
 * This function provide a message showing the user 
 * how many times he has seen the current profile
 */
function theme_stalker_user($variables) {
    global $user;
    
    // ultilizacao da funcao t() para traducao de interface
    $message = t("@username: You've seen this profile <strong>@num times",
            // @variavel nao sera traduzido, passe um array com os valores dinamicos a serem apresentdos
            array("@username" => $user->name, "@num" => $_SESSION["stalker"][$variables["account"]->uid]));
    
    return $message;
}