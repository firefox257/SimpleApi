const Map = (function()
{
    var maps = {};


    var atthis = function (class1, val)
    {
        var n2 = class1.name;
        var n1 = val.constructor.name;
        var o = new class1();
        for(var i in val)
        {
            if(i in o)
            {
                if(typeof val[i] != 'function' && typeof o[i] != 'function') o[i] = val[i];
            }
        }
        maps[n1][n2].tiefunc(val, o);
        return o;
    };
    atthis.Set = function (class1, class2, tiefunc)
    {
        var n1 = class1.name;
        var n2 = class2.name;
        
        if(maps[n1] == undefined)maps[n1] = {};
        maps[n1][n2] = {
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
    id;
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

var src = `

`;
