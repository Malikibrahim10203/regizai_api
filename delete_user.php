<?php

    include 'connection.php';

    $id = $_POST['id'];


    $sql = "DELETE FROM users WHERE id='$id'";
    $result = $connect->query($sql);

    $check = $connect->query("SELECT * FROM users WHERE id='$id'");


    if($check->num_rows == 0) {
        $user = array();

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