<?php
$name = $_POST['name'];
$email = $_POST['email'];
$subject = $_POST['subject'];
$message = $_POST['message'];

$email_from = "info@yourwebsite.com";

$email_subject = "New Form Submission";

$email_body = "User name: $name.\n".
              "User email: $email.\n".
              "User subject: $subject.\n".
              "User message: $message.\n";

$to = 'DDDD@DDDD.fr'

$headers = "From: $email_from \r\n";

$headers .= "Reply-To : $email";

mail($to, $email_subject, $email_body, $headers);

header("Location: contact.html");

?>