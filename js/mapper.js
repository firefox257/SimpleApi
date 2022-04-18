const Map = (function()
{
    var maps = {};


    var atthis = function (class2, val)
    {
        var n2 = class2.name;
        var n1 = val.constructor.name;

        var mi = maps[n1][n2].defs;

        var o = new class2();
        for(var i in val)
        {
            var ii = i.toLowerCase();
           
            var iii = mi[1][ii];

            if(ii in mi[1])
            {
                if(typeof val[i] != 'function' && typeof o[iii] != 'function') o[iii] = val[i];
            }
        }
        maps[n1][n2].tiefunc(val, o);
        return o;
    };
    atthis.Set = function (class1, class2, tiefunc)
    {
        var n1 = class1.name;
        var n2 = class2.name;

        var o1 = new class1();
        var o2 = new class2();

        var defs=[{}, {}];
        for(var i in o1)
        {
            defs[0][i.toLowerCase()] = i;
        }
        for(var i in o2)
        {
            defs[1][i.toLowerCase()] = i;
        }

      
        
        if(maps[n1] == undefined)maps[n1] = {};
        maps[n1][n2] = {
            defs: defs,
            tiefunc: tiefunc
        };
    };
    return atthis;
    
})();




class try1
{
    first;
    last;
    id;
    other;
}

class try2
{
    name;
    Id;
}

Map.Set(try1, try2, function(i, o)
{
    o.name = `${i.first} ${i.last}`;

});


var t1 = new try1;
t1.first = "name 1";
t1.last = " last name";
t1.id = "id123";
t1.other = "here 123";

var t2 = Map(try2, t1);
console.log(t2);




class User
{

    first;
    last;
    id;
    
}



/*

var v1 =Object.assign(new User(), {
    first:"first nemae",
    last:"lastname",
    id: 123
});

console.log("here434344");
console.log(v1);
console.log(v1.constructor.name);
*/
