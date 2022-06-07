//dependency injection.
const DI = (function()
{
    var objs = [];
    var atcount = 0;
    return {
        //Singlton
        Singlton(cl)
        {
            var at= {
                cl: cl,
               obj: (function()
               {
                   var at = new cl();
                   if(at.$di != undefined)
                    {
                        for(var i in at.$di)
                        {
                            //console.log(at.$di[i]);
                             at.$di[i] = objs[i].get();
                        }
                    }

                    return at;
               })(),
               getObj()
               {
                   return this.obj;
               },
               get()
               {
                    return this.getObj();
               }
            };
            objs[cl.name] = at;

        },
        //Transitory
        Transitory(cl)
        {
            var at = {
                cl: cl,
                get()
                {
                    var at =  new this.cl();

                    if(at.$di != undefined)
                    {
                        for(var i in at.$di)
                        {
                            at.$di[i] = objs[i].get();
                        }
                    }

                 
                   return at;
                }
            };
            objs[cl.name] = at
        },
        Reset()
        {
            atcount++;
        },
        //Scope
        Scope(cl)
        {
            var at= {
                atcountthis: atcount,
                cl: cl,
               obj: (function()
               {
                   var at = new cl();
                   if(at.$di != undefined)
                    {
                        for(var i in at.$di)
                        {
                            //console.log(at.$di[i]);
                             at.$di[i] = objs[i].get();
                        }
                    }

                    return at;
               })(),
               getObj()
               {
                   if(at.atcountthis != atcount)
                   {
                       at.obj = (function()
                       {
                           var at = new cl();
                           if(at.$di != undefined)
                            {
                                for(var i in at.$di)
                                {
                                    //console.log(at.$di[i]);
                                     at.$di[i] = objs[i].get();
                                }
                            }
        
                            return at;
                       })();
                       at.atcountthis = atcount;
                   }
                   return this.obj;
               },
               get()
               {
                    return this.getObj();
               }
            };
            objs[cl.name] = at;

        },

        Get(cl)
        {
            return objs[cl.name].get();
        }
    };
})();
globalThis.DI = DI;

/*
class try1
{
    x = 1;
   
    constructor()
    {

    }
    func()
    {
        console.log("here1");
    }
}
class try2
{
    $di = {try1};
    constructor()
    {

    }
    func()
    {
        console.log("and more");
    }
}

DI.T(try1);
DI.T(try2);

var v = DI.Get(try2);
v.$di.try1.func();

*/






