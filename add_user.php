<?php

    include 'connection.php';

    $name = $_POST['name'];
    $email = $_POST['email'];
    $password = $_POST['password'];
    $role = $_POST['role'];
    $created_at = date("Y-m-d H:i:s");
    $updated_at = date("Y-m-d H:i:s");
    $pw =  password_hash($password, PASSWORD_DEFAULT);

    $sql = "INSERT INTO users (name,email,password,role) VALUES ('$name','$email','$pw','$role')";

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