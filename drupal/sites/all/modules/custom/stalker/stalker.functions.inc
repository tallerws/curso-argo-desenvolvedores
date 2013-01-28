<?php

/**
 * Gets the view count from the database
 * @param type $uid User viewing
 * @param type $pid Profile being view
 */
function stalker_get_count($uid, $pid) {

    $result = db_select("stalker", "qualquer")->fields("qualquer")->condition("uid", intval($uid), "=")
                    ->condition("pid", intval($pid), "=")->execute()->fetchAssoc();

    return ($result) ? intval($result["view_counter"]) : 0;
}

/**
 * persists the count on the database
 * @param type $uid User viewing
 * @param type $pid Profile being view
 */
function stalker_set_count($uid, $pid, $count) {
// Faz update por padrao e ve se foi updated
    $r = db_update("stalker")->fields(array("view_counter" => intval($count)))->condition("uid", intval($uid), "=")
                    ->condition("pid", intval($pid), "=")->execute();

    if (!$r) {
        db_insert("stalker")->fields(array("uid" => $uid, "pid" => $pid, "view_counter" => $count))->execute();
    }
}

/**
 * Gets the list of 5 top stalkers of a profile
 * @param int $pid Profile User ID
 * @return array containg rows of stalkers or FALSE if none
 */
function stalker_get_top_stalkers($pid){
    
    $result = db_select("stalker", "s")->fields("s")->condition("pid", intval($pid))
            ->orderBy("view_counter", "DESC")->range(0, 5)->execute()->fetchAllAssoc("uid");
    
    
    return ($result)? $result : FALSE;
    
}