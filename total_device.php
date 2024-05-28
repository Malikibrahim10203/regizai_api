<?php

    include 'connection.php';

    $sql = "SELECT COUNT(*) as total FROM devices";

    $result = $connect->query($sql);

    if($result->num_rows > 0) {
        $user = array();
        while ($row = $result->fetch_assoc()) {
            $user[] = $row;
        }

        echo json_encode(array(
            "success"=>true,
            "user"=>$user,
        ));
    } else {
        echo json_encode(array(
            "success"=>false,
        ));
    }
?>