var
        n,t,i,j,d:longint;
        check:array[0..9] of boolean;
        res:int64;
procedure add(n:int64);
var     t:longint;
begin
        while n<>0 do
        begin
                check[n mod 10]:=true;
                n:=n div 10;
        end;
end;
function kt:boolean;
var     i:longint;
begin
        for i:=0 to 9 do
                if check[i]=false then exit(false);
        exit(true);
end;
procedure xuly;
begin
        d:=0;
        while kt=false do
        begin
                inc(d);
                add(n*d);
        end;
        res:=n*d;
end;
procedure nhap;
begin
        readln(t);
        while t>0 do
        begin
        dec(t);
        readln(n);
        fillchar(check,sizeof(check),false);
        if n<>0 then
        begin
                xuly;
                writeln(res);
        end
        else writeln('Awake!');
        end;
end;
begin
        {assign(input,'coutingsheep.inp');
        assign(output,'coutingsheep.out');
        reset(input);
        rewrite(output);}
        nhap;
        {close(input);
        close(output);}
end.
