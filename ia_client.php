#!/usr/local/bin/php
<?php
/*
** ia.php for zappy in /home/hero/zappy
**
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
**
** Started on  Sun Jul 14 10:23:09 2013 Marin Alcaraz
** Last update Sun Jul 14 10:23:09 2013 Marin Alcaraz
 */

function connect_zappy($host, $port)
{
    $fp = 0;

    $fp = stream_socket_client("tcp://$host:$port",
        $errno, $errstr, 30);
    if (!$fp)
        echo "$errstr ($errno)\n";
    return ($fp);
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
    "gauche\n",
    "prend food\n",
    "incantation\n",
    "fork\n"
);

$array = array();

for ($i = 0; $i < 100; ++$i)
{
    if ($array[$i] = connect_zappy($host, $port))
    {
        $team = "$options[n]\n";
        fwrite($array[$i], $team);
        echo fgets($array[$i], 1024);
    }
}

for ($j = 0; 1; $j = ($j + 1) % count($array))
{
    $r_command = rand(1, count($command)) - 1;
    fwrite($array[$j],
        $command[$r_command]);
    echo fgets($array[$j], 1024);
}
foreach ($array as $a)
{
    fclose($a);
}
?>
