# **Laboratório de Estrutura de Dados II**

### Repositório criado com finalidade de responder as atividades da disciplina e enviar para o professor.

</br>

## Manual de instruções do Repositórios

</br>

📖 **Guia Básico**

</br>

* git clone

  - O git clone serve para que você possa clonar todo o projeto para a sua máquina.
  - Para utilizar o git clone, e baixar este repositório, basta utilizar o comando a baixo com no seu terminal.

  ```bash
    git clone https://github.com/caioRafael/LaboratorioDeEstruturaDeDados2.git
  ```
  - por ser um repositório privado ele irá pedir autenticação para poder clona-lo 

* git pull
  
  - O git pull serve para atualizar todo o projeto, ou uma branch( divisão utilizada para controlar as versões do projeto) expecifica. 
  - **Este comando deve ser utilizado apenas quando alguma outra pessoa subir alguma alteração para o github, por isso é importante a cominucação da equipe**
  - No caso deste repositório iremos utilizar a branch main, então deve ser utilixado o comando a baixo

  ```bach
    git pull origin main
  ```

* git add e git commit
  
  - O git add serve para adicionar todas as suas ultimas alteraçẽos no proximo commit que você for dar. Para utilizalo basta usar o comando abaixo

  ```bash
    git add .
  ```
  - Após utilizar o git add, é utilizado o git commit. Ele é utilizado para salvar todas as modificações que foram feitas, localmente
  - cada commit deve ter um nome, que de preferencia, definam o que foi feito nas ultimas modificações

  ```bash
    git commit -m "nome do commit"
  ```

* git push
  - o git push serve para subir os ultimo commits feitos em sua maquina local para o repositório virtual no github
  - **É extremamente importante que seja feito os comandos "git add" e "git commit" antes de usar o git push**
  - O git push deve ser feito de forma que mande as alterações para auma branch expecifica, no caso desse repositório, a branch main. Segue o exemplo de código a baixo.

  ```bash
    git push origin main
  ```

📑 **Recomendações para subir alterações para o github**

* Para subir alguma alteração para o github, é importante que sejam seguidas os seguintes passos, para que não haja problemas e conflitos com as demais alterações
  
  - 1° - Quando terminar as alterações utilize os comando **"git add"** e **"git commit"**;
  - 2° - Após realizar as alterações e utilizar os comandos da primeira instrução, utilise o comando **"git pull"** para prevenir de conflitos nas atividades realizadas;
  - 3° - Feitos as instruções 1 e 2 utilize o comando **git push** para enfim subir as alterações para o github;

⁉️ **Em caso de duvida**

* Em caso de duvida, não se acanhe e pessa ajuda a alguem que ja conhece o git.