Application Background:
<p>
The main goal of this application isto create a platform where dog owners and dog enthusiasts
can be brought together. Specifically, our service aims to bring two types of people together:
dog owners who cannot walk their dogs, and dog walkers who want to walk dogs. The
commonality here is that a dog needssome outdoor time;somebody just needsto walk with it.
This is where Doggie Walk comes into play.<p>
**Customer** <p>
The target audience of our application is separated into two profiles: dog owners and dog
walkers. This separation is not determined based on demographics or any other physical factor,
but rather, these two user types are differentiated based on their individual needs. These needs
are described below:<p>
**Dog Owners**<p>
Dog Owners, by definition, have at least one pet dog that legally belongs to them. For some
reason or another, these people may find themselves in a situation in which they are unable to
walk their dog(s). Such circumstances may include, but is not limited to: medical issues (e.g.
broken leg, flu, headache...), time constraints(too busy due to a new job, running errands, etc.),
or unexpected emergencies, for example. Whatever the reason may be, it is understood that
these Dog Owners cannot walk their dog and is in need of someone else to do so on their
behalf. For some fortunate people, they may have a network of family or friendsthat can help
them walk their pet. Doggie Walk effectively provides a network of available “Dog Walkers”
who can help those in need of their service.<p>
**Dog Walkers**<p>
Unlike Dog Owners, Dog Walkers is an open category that anyone can fall under, regardless of
how old they are, what job they have, or what language they speak; aslong asthere is a passion
for dogs, anyone and everyone can be a Dog Walker. The core issue for these usersisthat they
may be unable to have their own dog: heavy expenses, unsuitable lifestyle and environment, or
the reluctance of committing long­term to owning a pet are just some common examples.
Doggie Walk enables these dog­less people to have quality dog­time with other people’s dogs
by walking and playing with them, which in turn acts as a favour for the Dog Owners who need
the helping hand.<p>
By connecting these two user types together, Doggie Walk helps them both get what they want!<p>



Start Instructions:
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
**Flask framework**
**PostgreSql**


Feel free to modularize the code but PLEASE document it well so no one gets confused and time is not wasted. <p>
