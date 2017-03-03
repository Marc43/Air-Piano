# Air-Pianoo
## De la música a los dedos...

### Como va a funcionar el piano (por ahora, sujeto a cambios):

El piano de aire es un instrumento que depende totalmente de la posición de las manos y los dedos. La altura de cada mano respecto al leapmotion definirá la octava en la que estemos tocando con esa mano (siendo las posiciones más bajas las correspondientes a las octavas más graves y las más altas las que se corresponden a las octavas mas agudas).

El como tocar una nota en específico es algo que viene dado por el/los dedos que tengamos flexionados. Cada dedo tendrá mapeada una nota (de "do" a "si", respectivamente), reservándonos algunos dedos para mapear dos notas (principalmente el dedo índice y el corazón, ya que son aquellos en los que en general la gente tiene ms movilidad).


### Como implementaremos el piano:

Por ahora nos basaremos en tres superclases:

1. **Detectar Manos**: Clase encargada de usar el API de Leamotion para devolver los datos que nos interesan de entre todos los datos que recibe el Leapmotion.

2. **Convertir Datos**: Clase intermedia, que se encargará de coger los datos de **Detectar Manos** y simplificarlos para facilitarle la vida a **Reproducir Notas**.

3. **Reproducir Notas**: Clase que recibirá los datos simplificados de **Convertir Datos** y los enviará FMOD para que reproduzca las notas que correspondan.

El como estarán cada clase implementadas por dentro es algo que corresponderá al programador al que le toque.
