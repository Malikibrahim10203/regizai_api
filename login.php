<?php 
    error_reporting(0);
    include 'connection.php';

    $email = $_POST['email'];
    $pass = $_POST['password'];


    $sql = "SELECT * FROM users WHERE email='$email'";
    $result = $connect->query($sql);

    $result1 = $connect->query("SELECT * FROM users WHERE email='$email'");

    while ($raw = mysqli_fetch_assoc($result1)) {
        if (password_verify($pass, $raw['password'])) {
            if($result->num_rows > 0) {
                $user = array();
                while ($row = $result->fetch_assoc()) {
                    $user[] = $row;
                }
        
                echo json_encode(array(
                    "success" => true,
                    "user" => $user[0],
                ));
            } else {
                echo json_encode(array(
                    "success" => false,
                ));
            }
        }
    }
    
    

?>