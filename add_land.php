<?php

    include 'connection.php';

    $name = $_POST['name'];
    //$image = $_POST['image'];
    $description = $_POST['description'];
    $polygon = $_POST['polygon'];
    //$area = $_POST['area'];
    //$image = $_POST['image'];
    $crop_status = $_POST['crop_status'];
    $crop_planted_at = date("Y-m-d", strtotime($_POST['crop_planted_at']));
    $user_id = $_POST['user_id'];
    //$deleted_at = $_POST['Y-m-d H:i:s'];
    $created_at = date("Y-m-d H:i:s");
    $updated_at = date("Y-m-d H:i:s");

    $sql = "INSERT INTO lands (name,description,polygon,crop_status, crop_planted_at, user_id) VALUES ('$name','$description','$polygon','$crop_status', '$crop_planted_at','$user_id')";

    $result = $connect->query($sql);

?>