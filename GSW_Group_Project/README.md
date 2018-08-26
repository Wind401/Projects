To start app:
vagrant up <p>
vagrant provision <p>
vagrant ssh <p>
cd project <p>
run **gunicorn --bind 0.0.0.0:5002 wsgi** <p>

TroubleShoot:
Cannot connect to port 5002, port already in use <p>
run **fuser -k 5002/tcp > /dev/null 2>&1; exit 0** <p>


Technologies used:
**Gunicorn** ‘Green Unicorn’ is a Python WSGI HTTP Server for UNIX. <p>
**Nginx** is an HTTP and reverse proxy server.


currently everything works, just follow the website introduction and try every part;

you can use userEmail: user1@sfu.ca  userPassword: 123456 for grading;

easy to miss:
users get email notification when they register, when they receive message from other users;
users get inbox message when they receive a review;
the search bar can search user by name, email. search events and users by search city, search dog by breed, also can search event by name;
user can give other users review but cannot give himself review;

The url we use:
0.0.0.0:5002

Main code is in: doggiewalk.py <p>
Feel free to modularize the code but PLEASE document it well so no one gets confused and time is not wasted. <p>
