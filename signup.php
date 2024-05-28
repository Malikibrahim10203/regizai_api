<?php

    include 'connection.php';

    $email = $_POST['email'];
    $password = $_POST['password'];
    $name = $_POST['name'];
    $gender = $_POST['gender'];
    $birth = $_POST['birth'];
    $width = $_POST['width'];
    $height = $_POST['height'];
    $created_at = date("Y-m-d H:i:s");
    $updated_at = date("Y-m-d H:i:s");
    $pw =  password_hash($password, PASSWORD_DEFAULT);

    $sql = "INSERT INTO users ( name, email, password, gender, birth, width, height, created_at, updated_at) VALUES ('$name','$email','$pw','$gender','$birth',$width, $height,'$created_at','$updated_at')";

    $result = $connect->query($sql);

    if($result === TRUE) {

        echo json_encode(array(
            "success"=>true,
        ));
    } else {
        echo json_encode(array(
            "success"=>false,
        ));
    }
?>