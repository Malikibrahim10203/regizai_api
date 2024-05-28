<?php

    include 'connection.php';

    $id = $_POST['id'];

    $sql = "SELECT * FROM catatan_harian LEFT JOIN makanan ON catatan_harian.id_makanan = makanan.id_makanan WHERE catatan_harian.id_user=$id";

    $result = $connect->query($sql);

    if($result->num_rows > 0) {
        $catatan = array();
        while ($row = $result->fetch_assoc()) {
            $catatan[] = $row;
        }

        echo json_encode(array(
            "success"=>true,
            "catatan"=>$catatan,
        ));
    } else {
        echo json_encode(array(
            "success"=>false,
        ));
    }
?>