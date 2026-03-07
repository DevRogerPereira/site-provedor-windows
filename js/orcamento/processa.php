<?php

	require_once("../../adm/conexao.php");

	if( $_SERVER['REQUEST_METHOD'] == 'POST' )
	{
			$data = date("Y-m-d H:i:s");
			$data_mail = date("d/m");
			$url_ft = md5(uniqid(time()));
			$mensagem = addslashes(getPost('mensagem'));

			$plano_id = trim((string) getPost('plano_id'));
			
			if ($plano_id !== '') {
			
				// segurança (mesmo sendo ID)
				$plano_id_safe = htmlspecialchars($plano_id, ENT_QUOTES, 'UTF-8');
			
				$assunto = $plano_id_safe . ': ';
			
				$tr_plano_id = '
				<tr>
					<td align="left" valign="top"></td>
					<td align="center" valign="top" style="padding:20px 0px 10px 0px;">
						<span style="padding:40px 0px 10px 0px;display:block;">
							<span style="font-size:12px;color:#333;font-family:Arial;padding:0px;display:block;">
								<strong>Plano:</strong>
							</span>
							<span style="font-size:18px;color:#59595C;font-family:Arial;padding:5px 0px 10px 0px;display:block;">
								' . $plano_id_safe . '
							</span>
						</span>
					</td>
					<td align="left" valign="top"></td>
				</tr>';
			
			} else {
			
				$assunto = 'SITE: ';
				$tr_plano_id = '';
			}



			if (getPost('input_nome') == true) {
					
				$tr_nome = "<tr>
					  <td align=\"left\" valign=\"top\"></td>
					  <td align=\"center\" valign=\"top\" style=\"padding:20px 0px 10px 0px;\"><span style=\"font-size:12px;color:#333;font-family:Arial;padding:0px 0px 0px 0px;display:block;\"><strong>Nome:</strong></span><span style=\"font-size:18px;color:#59595C;font-family:Arial;padding:5px 0px 10px 0px;\">".mb_strtolower(getPost('input_nome')) ."</span>                                          
					  <td align=\"left\" valign=\"top\"></td>
					  </tr>";

			}

			if (getPost('endereco') == true) {
					
				$tr_endereco = "<tr>
					  <td align=\"left\" valign=\"top\"></td>
					  <td align=\"center\" valign=\"top\" style=\"padding:20px 0px 10px 0px;\"><span style=\"font-size:12px;color:#333;font-family:Arial;padding:0px 0px 0px 0px;display:block;\"><strong>Endereço:</strong></span><span style=\"font-size:18px;color:#59595C;font-family:Arial;padding:5px 0px 10px 0px;\">".mb_strtolower(getPost('endereco'))."</span>                                          
					  <td align=\"left\" valign=\"top\"></td>
					  </tr>";

			}

			if (getPost('uf') == true) {
					
				$tr_uf = " - ".mb_strtolower(getPost('uf'))."";

			}

			if (getPost('cidade_id') == true) {
					
				$tr_cidade_id = "<tr>
					  <td align=\"left\" valign=\"top\"></td>
					  <td align=\"center\" valign=\"top\" style=\"padding:20px 0px 10px 0px;\"><span style=\"font-size:12px;color:#333;font-family:Arial;padding:0px 0px 0px 0px;display:block;\"><strong>Cidade:</strong></span><span style=\"font-size:18px;color:#59595C;font-family:Arial;padding:5px 0px 10px 0px;\">".mb_strtolower(getPost('cidade_id')) . $tr_uf ."</span>                                          
					  <td align=\"left\" valign=\"top\"></td>
					  </tr>";

			}

			if (getPost('cep') == true) {
					
				$tr_cep = "<tr>
					  <td align=\"left\" valign=\"top\"></td>
					  <td align=\"center\" valign=\"top\" style=\"padding:20px 0px 10px 0px;\"><span style=\"font-size:12px;color:#333;font-family:Arial;padding:0px 0px 0px 0px;display:block;\"><strong>CEP:</strong></span><span style=\"font-size:18px;color:#59595C;font-family:Arial;padding:5px 0px 10px 0px;\">".mb_strtolower(getPost('cep'))."</span>                                          
					  <td align=\"left\" valign=\"top\"></td>
					  </tr>";

			}

			if (getPost('input_telefone') == true) {
					
				$tr_telefone = "<tr>
					  <td align=\"left\" valign=\"top\"></td>
					  <td align=\"center\" valign=\"top\" style=\"padding:20px 0px 10px 0px;\"><span style=\"font-size:12px;color:#333;font-family:Arial;padding:0px 0px 0px 0px;display:block;\"><strong>Telefone:</strong></span><span style=\"font-size:18px;color:#59595C;font-family:Arial;padding:5px 0px 10px 0px;\">".mb_strtolower(getPost('input_telefone'))."</span>                                          
					  <td align=\"left\" valign=\"top\"></td>
					  </tr>";

			}

			$tr_email = ''; // valor padrão vazio
			
			$input_email = trim((string) getPost('input_email'));
			
			if ($input_email !== '' && filter_var($input_email, FILTER_VALIDATE_EMAIL)) {
			
				$email_safe = htmlspecialchars(mb_strtolower($input_email, 'UTF-8'), ENT_QUOTES, 'UTF-8');
			
				$tr_email = '
				<tr>
					<td align="left" valign="top"></td>
					<td align="center" valign="top" style="padding:20px 0px 10px 0px;">
						<span style="font-size:12px;color:#333;font-family:Arial;padding:0px;display:block;">
							<strong>E-mail:</strong>
						</span>
						<span style="font-size:18px;color:#59595C;font-family:Arial;padding:5px 0px 10px 0px;display:block;">
							' . $email_safe . '
						</span>
					</td>
					<td align="left" valign="top"></td>
				</tr>';
			}
			
			if (getPost('localidade') == true) {
					
				$tr_localidade = "<tr>
					  <td align=\"left\" valign=\"top\"></td>
					  <td align=\"center\" valign=\"top\" style=\"padding:20px 0px 10px 0px;\"><span style=\"font-size:12px;color:#333;font-family:Arial;padding:0px 0px 0px 0px;display:block;\"><strong>localidade:</strong></span><span style=\"font-size:18px;color:#59595C;font-family:Arial;padding:5px 0px 10px 0px;\">".mb_strtolower(getPost('localidade'))."</span>                                          
					  <td align=\"left\" valign=\"top\"></td>
					  </tr>";

			}

			$situacao_data = date("Y-m-d");

			$query = mysqli_query($conexao,"INSERT INTO crm VALUES (NULL, 'N', '".$url_ft."', '".getPost('cidade_id')."', '".getPost('plano_id')."', '".getPost('nome_amigo')."', '".getPost('localidade')."', '".getPost('cidade_id')."', '".getPost('input_nome')."', '".getPost('input_telefone')."', '".getPost('input_email')."')");

			$query_id = mysqli_insert_id($conexao);

			require 'PHPMailerAutoload.php';
			require 'class.phpmailer.php';
			
			$mailer = new PHPMailer;

			$mailer->isSMTP();
			
			$mailer->SMTPOptions = array(
				'ssl' => array(
					'verify_peer' => false,
					'verify_peer_name' => false,
					'allow_self_signed' => true
				)
			);
			
			$nomeremetente     = strtoupper($tsite) . " / COMERCIAL";
			$data_rodape	   = date("d/m/Y");
			$hora			   = date("H:i");
			$assunto = "=?UTF-8?B?". base64_encode( $assunto . "" . getPost('input_nome')) . "?=";
			
			$mailer->Host = 'smtp.driblepropaganda.com.br';
			$mailer->SMTPAuth = true;
			$mailer->IsSMTP();
			$mailer->isHTML(true);
			$mailer->Port = 587;
			
			$mailer->CharSet = 'UTF-8';
			
			$mailer->Username = 'no-response@driblepropaganda.com.br';
			$mailer->Password = '52Rd3d$3825';
			
			$corpoMSG = '<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"><html>
			<head>
			<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
			</head>
			<title>LEAD</title>
			<body>
			<table width="100%" height="100%" border="0" align="center" cellpadding="0" cellspacing="0" bgcolor="#E6E7E7">
			<tr>
			  <td align="center" valign="top"><table width="570" border="0" align="center" cellpadding="0" cellspacing="0">
				<tr>
				  <tr>
					<td align="center" valign="top"><p><font size="1" face="Arial, Helvetica, sans-serif" color="#59595C">Adicione <strong>'.$email.'</strong> &agrave; sua lista de contatos para garantir o recebimento de todos os nossos emails.</font></p></td>
				  </tr>
							        <td width="416" align="left" valign="top"><table width="570" border="0" align="left" cellpadding="0" cellspacing="0" bgcolor="#FFFFFF">
                                      <tr>
                                        <td colspan="3" align="left" valign="top" bgcolor="#FFFFFF"></td>
                                      </tr>
                                      <tr>
                                        <td width="24" align="left" valign="top"></td>
                                        <td width="503" align="left" style="padding:0px 0px 0px 0px;">&nbsp;</td>
                                      </tr>
                                      <tr>
                                        <td align="left" valign="top"></td>
                                        <td align="left" style="padding:0px 0px 0px 0px;">&nbsp;</td>
                                      </tr>
                                      <tr>
                                        <td align="left" valign="top" style="background:#66F;"></td>
                                        <td align="center" valign="top" style="background:#66F;padding:40px 0px 40px 0px;"><span style="font-size:22px;color:#fff;font-family:Arial;padding:10px 0px 10px 0px"><strong>'.getPost('input_nome').'</strong>,<br>
                                          é um novo lead.</span>
                                        <td width="24" align="left" valign="top" style="background:#66F;"></td>
                                      </tr>
                                      <tr>
                                        <td align="left" valign="top"></td>
                                        <td align="center" valign="top" style="padding:40px 0px 0px 0px;"><span style="font-size:12px;color:#333;font-family:Arial;padding:0px 0px 0px 0px;display:block;"><strong>Telefone:</strong></span><span style="font-size:18px;color:#59595C;font-family:Arial;padding:5px 0px 10px 0px;">'.getPost('input_telefone').'</span>
                                        <td align="left" valign="top"></td>
                                      </tr>
'.$tr_plano_id . $tr_nome . $tr_telefone . $tr_email .'
<tr>
  <td align="left" valign="top" style="padding:10px 0px 40px 0px"></td>
  <td align="center" valign="top" style="padding:10px 0px 40px 0px">
    <td align="left" valign="top" style="padding:10px 0px 40px 0px"></td>
</tr>
                                    </table></td>
				</tr>
			  <tr>
				<td align="left" valign="top"></td>
			  </tr>
			  <tr>
				<td align="center" valign="top"><p><font size="1" face="Arial, Helvetica, sans-serif" color="#59595C">Essa mensagem foi enviada para <a href="mailto:'.$email.'" style="color:#3a94d1" target="_blank">'.$email.'</a>. Esta mensagem não deve ser respondida.<br>
				  Em caso de dúvidas, acesse nossa <a href="http://driblepropaganda.com.br" style="color:#3a94d1" target="_blank">central de atendimento</a> ou envie um email para <a href="mailto:'.$email.'" style="color:#3a94d1" target="_blank">'.$email.'</a>.</font></p></td>
			  </tr>
			</table></td>
			  </tr>
			</table>
			</body>
			</html>';
			
			$mailer->AddAddress($email, $nomeremetente);
			$mailer->AddAddress("artes@driblepropaganda.com.br", "DRIBLE");
			$mailer->From = 'no-response@driblepropaganda.com.br';
			$mailer->Sender = 'no-response@driblepropaganda.com.br';
			$mailer->FromName = $nomeremetente;

			$mailer->Subject = $assunto;

			$mailer->MsgHTML($corpoMSG);

			if(!$mailer->Send()) {
				
			   $msg = "Erro: " . $mailer->ErrorInfo;
			   
			} else {
				
			   $msg = "";
			   
			}

			if ($query) {
					
				echo "                            	<span class=\"cad-form-conf-titulo\">Olá, ".getPost('input_nome')."!<br>Recebemos seu pedido.</span>
                            	<span class=\"cad-form-conf-intro\">Em breve entraremos em contato para concluir sua compra.</span>";
					
			} else {
					
				echo "";
					
			}

	}
	function getPost( $key ){
		
		return isset( $_POST[ $key ] ) ? filter( $_POST[ $key ] ) : null;
		
	}
	function filter( $var ){
		
		return $var;
		
	}
?>


