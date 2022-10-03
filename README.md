# ReactionGame
A arduino program that I created in computer science class

Auf den 2 Breadboards sind 6 LEDs und jeweils ein dazugehöriger Taster angeschlossen.
Es gibt 2 verschiedene Spiele zwischen denen man mithilfe der jeweiligen Taster auswählen kann.
Sobald man das Programm startet, wird einem auf dem Serial Monitor eine Ladeanimation angezeigt.
Nach der Animation wird einem jeweils zu jedem Spiel eine Anleitung angezeigt.
Es war ein 3. Spiel geplant, welches auf Grund Platzmangels des Speichers aus dem Programm entnommen wurde.
Nachdem ein Spiel ausgewählt wurde erscheint wieder eine kurze Ladeanimation, welche danach zum Spiel überleitet.

Bei beiden Spielen leuchtet eine zufällige Lampe auf, welche erst ausgeht, sobald man den darunter liegenden Taster drückt. Dabei erhält man einen Punkt und die nächste zufällige Lampe geht an.

Spiel 1:

Bei Spiel 1 soll man so viele Punkte wie nur möglich innerhalb Einer Minute schaffen. Bei jedem erzielten Punkt wird einem auf dem Serial Monitor die Zeit, die bisher vergangen ist, die Reaktionszeit des letzten Punktes in Millisekunden und die bisher erzielten Punkte angezeigt.  

Nach Ablauf der Minute kann man auf dem Serial Monitor seine erzielten Punkte, sowie die durchschnittliche Reaktionszeit dieser Runde sehen.

Spiel 2:

Bei Spiel 2 muss der Spieler so schnell wie möglich 20 Punkte erzielen.
Auch hier kann man wie beim ersten Spiel seine erzielte Reaktionszeit dieses Punktes und die verbrauchte Zeit in Millisekunden sehen.
Nach dem Erreichen der 20 Punkten werden die Punkte ( hier immer 20 ) und ebenfalls wieder die durchschnittliche Reaktionszeit und verbrauchte Zeit der Runde in Millisekunden angezeigt.

Immer nachdem das ausgewählte Spiel beendet ist, hat man die Möglichkeit mit einem der Taster zum „Startbildschirm“ (Erklärung und Spielauswahl am Anfang) zurückzukehren oder das Spiel direkt neu zu starten.
