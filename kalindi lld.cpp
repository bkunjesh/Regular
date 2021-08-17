class Person{
    string firstName;
    string LastName;
    Location address;
    string phone;
    string email;
};
class Customer:class Person{
    string customerId;
    vector<ProductDetail> regular;
    CustomerStatus status;
    double pending_payment;
    vector<Transaction> txns;
};
class Admin:class Person{
    string adminId;
    string username;
    string password;
    Search searchObj;

    void AddCustomer(Customer customer);
    void ModifyCustomer(Customer customer);
    void RemoveCustomer(Customer customer);

    void AddTransaction(Transaction transaction, Customer customer);
    void ModifyTransaction(Transaction transaction);
    void RemoveTransaction(Transaction transaction);
};
class Location{
    string pin;
    string addressLine1; //houseno,flateno,buldingno,floor
    string addressLine2;//socityname
    string addressLine3;//socitypart
    string area;
    string city;
    string country;
};
class ProductDetail
{
    Shift shift;
    double liter;
    double cost;
};
enum Shift
{
    MORNING,
    EVENING
};
enum CustomerStatus
{
    ACTIVE,
    INACTIVE,
    PARTIAL_ACTIVE
};

class Transaction
{
    string txnId;
    Customer customer;
    Date date;
    ProductDetail productDetail;
};