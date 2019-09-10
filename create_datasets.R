rm(list = ls())
library(data.table)
b1=cbind(rnorm(25000,0.2),rnorm(25000,0.2),rnorm(25000,0.2))
b2=cbind(rnorm(25000,3,0.2),rnorm(25000,3,0.2),rnorm(25000,3,0.2))
b3=cbind(rnorm(25000,5,0.2),rnorm(25000,5,0.2),rnorm(25000,5,0.2))
b=rbind(b1,b2,b3)
b=as.data.frame(b)
fwrite(file="C:/Users/Francesco/Desktop/unifi/Magistrale/Parallel Computing/Progetto/raw_dataset.csv", b, row.names = FALSE, col.names = FALSE)


#prova2
N <- 100000

components <- sample(1:3,prob=c(0.34,0.33,0.33),size=N,replace=TRUE)
mus <- c(0,3,6)
sds <- sqrt(c(0.3,0.3,0.3))

samples <- cbind(rnorm(n=N,mean=mus[components],sd=sds[components]),rnorm(n=N,mean=mus[components],sd=sds[components]),rnorm(n=N,mean=mus[components],sd=sds[components]))
b=samples
b=as.data.frame(b)
summary(b)
fwrite(file="C:/Users/Francesco/Desktop/unifi/Magistrale/Parallel Computing/Progetto/raw_dataset.csv", b, row.names = FALSE, col.names = FALSE)

#2 milioni
library(data.table)
b=cbind(rnorm(500000),rnorm(500000,1.1),rnorm(500000,1.2),rnorm(500000,1.3))
b=as.data.frame(b)
fwrite(file="C:/Users/Francesco/Desktop/500k.csv", b, row.names = FALSE, col.names = FALSE)

#10k
library(data.table)
b=cbind(rnorm(100000),rnorm(100000),rnorm(100000))
b=as.data.frame(b)
fwrite(file="C:/Users/Francesco/Desktop/100k.csv", b, row.names = FALSE, col.names = FALSE)

