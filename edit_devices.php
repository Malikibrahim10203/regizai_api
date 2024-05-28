<?php

    include 'connection.php';

    $id = $_POST['id'];
    $id_old = $_POST['id_old'];
    $name = $_POST['name'];
    $name_old = $name;
    $land_id = $_POST['land_id'];
    $updated_at = date("Y-m-d H:i:s");

    $sql = "UPDATE devices SET id='$id', name='$name', updated_at='$updated_at' where id='$id_old'";

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