<?php

    include 'connection.php';

    $id = $_POST['id'];
    $name = $_POST['name'];
    $land_id = $_POST['land_id'];
    $created_at = date("Y-m-d H:i:s");
    $updated_at = date("Y-m-d H:i:s");

    $sql = "INSERT INTO devices (id,name,land_id,created_at,updated_at) VALUES ('$id','$name','$land_id','$created_at','$updated_at')";

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