build:
	docker build -t acedesign/arduinoml .

start:
	docker run --rm -it -p 8080:8080 --name arduinoml -d acedesign/arduinoml

stop:
	docker stop arduinoml

attach:
	docker exec -it arduinoml /bin/sh  

cli: build
	docker run --rm -it -p 8080:8080\
			   --entrypoint "/bin/bash" acedesign/arduinoml

publish:
	docker push acedesign/arduinoml