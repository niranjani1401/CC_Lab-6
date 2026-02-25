pipeline {
    agent any

    stages {

        stage('Checkout') {
            steps {
                checkout scm
            }
        }

        stage('Build Backend Image') {
            steps {
                sh 'docker build -t backend-app ./backend'
            }
        }

        stage('Run Backend Containers') {
            steps {
                sh '''
                docker rm -f backend1 backend2 || true
                docker run -d --name backend1 backend-app
                docker run -d --name backend2 backend-app
                '''
            }
        }

        stage('Build Nginx Image') {
            steps {
                sh 'docker build -t custom-nginx ./nginx'
            }
        }

        stage('Run Nginx') {
            steps {
                sh '''
                docker rm -f nginx || true
                docker run -d --name nginx -p 80:80 \
                --link backend1 \
                --link backend2 \
                custom-nginx
                '''
            }
        }
    }

    post {
        always {
            sh 'docker ps'
        }
    }
}

