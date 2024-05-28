<?php

    include 'connection.php';

    $id_capture = $_POST['id_capture'];
    $id_user = $_POST['id_user'];
    $id_makanan = $_POST['id_makanan'];
    $tgl_capture = date("Y-m-d H:i:s");
    $calories = $_POST['calories'];

    $sql = "INSERT INTO catatan_harian (id_capture,id_user,id_makanan,tgl_capture,calories) VALUES ('$id_capture','$id_user','$id_makanan','$tgl_capture','$calories')";

    $result = $connect->query($sql);

    if($result->num_rows > 0) {
        $data = array();
        while ($row = $result->fetch_assoc()) {
            $data[] = $row;
        }

        echo json_encode(array(
            "success"=>true,
            "data"=>$data,
        ));
    } else {
        echo json_encode(array(
            "success"=>false,
        ));
    }
?>