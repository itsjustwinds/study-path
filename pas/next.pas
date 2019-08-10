var
        x,k:int64;
        sx:ansistring;
        bit1,n,i,m:longint;
        h:boolean;
        min:char;
        r2:int64;
        sl:int64;
        r:array[1..61] of char;
        f:array[1..61,1..60,false..true] of int64;
procedure chuanbi;
begin
        sx:='';
        bit1:=0;
        for i:=1 to 60 do
        begin
                sx:=char(x mod 2+48)+sx;
                if x mod 2=1 then inc(bit1);
                x:=x div 2;
        end;

end;
procedure ghikq;
begin
        r2:=0;
        for i:=1 to n do
                r2:=r2*2+(ord(r[i])-48);
                if r2<=trunc(1e15)then write(r2)
                else write(-1);
end;
function tinh(i,c:longint;ok:boolean):int64;
var     j:char;
        v:char;
begin
        if f[i,c,ok]>-1 then exit(f[i,c,ok]);
        if (i>n) then exit(ord((c=0)and (ok)));
        if ok then min:='0'
        else min:=sx[i];
        for j:=min to '1' do
        SL:=sl+tinh(i+1,c+ord(v='1'),ok or (v>sx[i]));
end;
procedure lankq(i,c:longint;ok:boolean);
var
        min,j,v:char;
        k:longint;
        sl:int64;
begin
        if f[i,c,ok]>-1 then exit;
        if (i>n) then exit;
        if ok then min:='0'
        else min:=sx[i];
        for j:=min to '1' do
        begin
        SL:=sl+tinh(i+1,c+ord(v='1'),ok or (v>sx[i]));
        if sl<k then k:=k-sl
        else begin
                r[i]:=v;
                lankq(i+1,c+ord(v='1'),ok or (v>sx[i]));
                break;
        end;
        end;
end;
begin
        assign(input,'next.inp');
        assign(output,'next.out');
        reset(input);
        rewrite(output);
        readln(x,k);
        n:=60;
        chuanbi;
        for i:=1 to 61 do
                for m:=1 to 60 do
                        for h:=false to true do
                                f[i,m,h]:=-1;
        if tinh(1,0,false)<k then write(-1)
        else begin
                lankq(1,0,false);
                ghikq;
        end;
        close(input);
        close(output);
end.