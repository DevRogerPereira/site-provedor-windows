        <section id="areas-atuacao" class="section-location">
            <div class="container">
                <div class="row">
                    <div class="box-content col-lg-5">
                        <h2 class="title">Veja nossas áreas de atuação:</h2>

                        <ul>
						<?php
                        
                        $sql = mysqli_query($conexao,"SELECT * FROM planos_localidades WHERE del = 'N' ORDER BY nome ASC");
                        
                        while ($dados_planos = mysqli_fetch_object($sql)) {
                        
                        ?>
                            <li><?php echo $dados_planos->nome ?></li>
						<?php } ?>
                        </ul>
                    </div>

                    <div class="box-image col-lg-7">
                        <figure>
                            <img src="images/mapa.png" alt="Mapa">
                        </figure>
                    </div>
                </div>
            </div>
        </section>