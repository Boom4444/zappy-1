#!/usr/local/bin/php
<?php
/*
** ia_client.php for zappy in /home/ignati_i/zappy/zappy
**
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
**
** Started on  Sun Jul 14 10:23:09 2013 Marin Alcaraz
   Last update Sun Jul 14 21:37:26 2013 ivan ignatiev
 */

error_reporting(0);

function connect_zappy($host, $port, $team)
{
  $fd = stream_socket_client("tcp://$host:$port",
      $errno, $errstr, 30);
  if (!$fd)
  {
    echo "$errstr ($errno)\n";
    if ($errno == 101)
       exit(0);
    return (0);
  }
  $data_b = stream_socket_recvfrom($fd, 1024);
  echo $data_b;
  stream_socket_sendto($fd, $team, 0);
  $data = stream_socket_recvfrom($fd, 1024);
  echo $data;
  stream_set_blocking($fd, FALSE);
  if (strncmp($data, 'ko', 2) != 0 && count($data)
     && strncmp($data_b, "BIENVENUE", 9) == 0)
    return ($fd);
  return (0);
}

$options = getopt("n:h:p:");

$team = "";
$inventaire = "";
$income = "";
$host = "";
$port = "";

if ($argc != 7)
{
  echo "usage: php client.php -n [TEAM NAME] -h [HOST] -p [PORT]\n";
  exit(0);
}

$host .= $options[h];
$port .= $options[p];
$fd = 0;

$command = array(
    "avance\n",
    "droite\n",
    "avance\n",
    "droite\n",
    "gauche\n",
    "prend food\n",
    "avance\n",
    "incantation\n",
    "fork\n",
    "gauche\n"
    );

$array = array();

$data = '';
$team = "$options[n]\n";

while (($fd = connect_zappy($host, $port, $team)) > 0)
{
  $array[] = $fd;
}

if (count($array))
{
  for ($j = 0; 1; $j = ($j + 1) % count($array))
  {
    $r_command = rand(1, count($command)) - 1;
    stream_socket_sendto($array[$j], $command[$r_command], 0);
    echo $command[$r_command];
    $data = stream_socket_recvfrom($array[$j], 1024);
    echo $data;
    if ($fd = connect_zappy($host, $port, $team))
    {
      $array[] = $fd;
    }
  }
}
?>
