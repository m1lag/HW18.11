#include <iostream>

using namespace std;

class TelephoneBook
{
    char* m_name;
    char* m_homePhone;
    char* m_workPhone;
    char* m_mobilePhone;
    char* m_additionalInformation;

public:
    TelephoneBook(const char* name, const char* homePhone, const char* workPhone, const char* mobilePhone, const char* additionalInformation)
    {
        m_name = new char[strlen(name) + 1];
        for (size_t i = 0; i <= strlen(name); ++i)
            m_name[i] = name[i];

        m_homePhone = new char[strlen(homePhone) + 1];
        for (size_t i = 0; i <= strlen(homePhone); ++i)
            m_homePhone[i] = homePhone[i];

        m_workPhone = new char[strlen(workPhone) + 1];
        for (size_t i = 0; i <= strlen(workPhone); ++i)
            m_workPhone[i] = workPhone[i];

        m_mobilePhone = new char[strlen(mobilePhone) + 1];
        for (size_t i = 0; i <= strlen(m_mobilePhone); ++i)
            m_mobilePhone[i] = mobilePhone[i];

        m_additionalInformation = new char[strlen(additionalInformation) + 1];
        for (size_t i = 0; i <= strlen(additionalInformation); ++i)
            m_additionalInformation[i] = additionalInformation[i];
    }

    TelephoneBook() 
        : m_name(nullptr)
        , m_homePhone(nullptr)
        , m_workPhone(nullptr)
        , m_mobilePhone(nullptr)
        , m_additionalInformation(nullptr) 
    {}

    TelephoneBook(const TelephoneBook& copy)
    {
        m_name = new char[strlen(copy.m_name) + 1];
        for (size_t i = 0; i <= strlen(copy.m_name); ++i)
            m_name[i] = copy.m_name[i];

        m_homePhone = new char[strlen(copy.m_homePhone) + 1];
        for (size_t i = 0; i <= strlen(copy.m_homePhone); ++i)
            m_homePhone[i] = copy.m_homePhone[i];

        m_workPhone = new char[strlen(copy.m_workPhone) + 1];
        for (size_t i = 0; i <= strlen(copy.m_workPhone); ++i)
            m_workPhone[i] = copy.m_workPhone[i];

        m_mobilePhone = new char[strlen(copy.m_mobilePhone) + 1];
        for (size_t i = 0; i <= strlen(copy.m_mobilePhone); ++i)
            m_mobilePhone[i] = copy.m_mobilePhone[i];

        m_additionalInformation = new char[strlen(copy.m_additionalInformation) + 1];
        for (size_t i = 0; i <= strlen(copy.m_additionalInformation); ++i)
            m_additionalInformation[i] = copy.m_additionalInformation[i];
    }

    TelephoneBook& operator=(const TelephoneBook& copy)
    {
        if (this == &copy) return *this;

        delete[] m_name;
        delete[] m_homePhone;
        delete[] m_workPhone;
        delete[] m_mobilePhone;
        delete[] m_additionalInformation;

        m_name = new char[strlen(copy.m_name) + 1];
        for (size_t i = 0; i <= strlen(copy.m_name); ++i)
            m_name[i] = copy.m_name[i];

        m_homePhone = new char[strlen(copy.m_homePhone) + 1];
        for (size_t i = 0; i <= strlen(copy.m_homePhone); ++i)
            m_homePhone[i] = copy.m_homePhone[i];

        m_workPhone = new char[strlen(copy.m_workPhone) + 1];
        for (size_t i = 0; i <= strlen(copy.m_workPhone); ++i)
            m_workPhone[i] = copy.m_workPhone[i];

        m_mobilePhone = new char[strlen(copy.m_mobilePhone) + 1];
        for (size_t i = 0; i <= strlen(copy.m_mobilePhone); ++i)
            m_mobilePhone[i] = copy.m_mobilePhone[i];

        m_additionalInformation = new char[strlen(copy.m_additionalInformation) + 1];
        for (size_t i = 0; i <= strlen(copy.m_additionalInformation); ++i)
            m_additionalInformation[i] = copy.m_additionalInformation[i];

        return *this;
    }

    ~TelephoneBook()
    {
        delete[] m_name;
        delete[] m_homePhone;
        delete[] m_workPhone;
        delete[] m_mobilePhone;
        delete[] m_additionalInformation;
    }

    const char* getName() const { return m_name; }
    const char* getHomePhone() const { return m_homePhone; }
    const char* getWorkPhone() const { return m_workPhone; }
    const char* getMobilePhone() const { return m_mobilePhone; }
    const char* getAdditionalInformation() const { return m_additionalInformation; }

    void setName(const char* name)
    {
        delete[] m_name;
        m_name = new char[strlen(name) + 1];
        for (size_t i = 0; i <= strlen(name); ++i)
            m_name[i] = name[i];
    }

    void setHomePhone(const char* homePhone)
    {
        delete[] m_homePhone;
        m_homePhone = new char[strlen(homePhone) + 1];
        for (size_t i = 0; i <= strlen(homePhone); ++i)
            m_homePhone[i] = homePhone[i];
    }

    void setWorkPhone(const char* workPhone)
    {
        delete[] m_workPhone;
        m_workPhone = new char[strlen(workPhone) + 1];
        for (size_t i = 0; i <= strlen(workPhone); ++i)
            m_workPhone[i] = workPhone[i];
    }

    void setMobilePhone(const char* mobilePhone)
    {
        delete[] m_mobilePhone;
        m_mobilePhone = new char[strlen(mobilePhone) + 1];
        for (size_t i = 0; i <= strlen(m_mobilePhone); ++i)
            m_mobilePhone[i] = mobilePhone[i];
    }

    void setAdditionalInformation(const char* additionalInformation)
    {
        delete[] m_additionalInformation;
        m_additionalInformation = new char[strlen(additionalInformation) + 1];
        for (size_t i = 0; i <= strlen(additionalInformation); ++i)
            m_additionalInformation[i] = additionalInformation[i];
    }

    void dataEntry() const
    {
        cout << "Name: " << m_name << endl;
        cout << "Home Phone: " << m_homePhone << endl;
        cout << "Work Phone: " << m_workPhone << endl;
        cout << "Mobile Phone: " << m_mobilePhone << endl;
        cout << "Additional Information: " << m_additionalInformation << endl;
    }
};

class PhoneBookManager
{
    TelephoneBook m_contacts[100];
    int m_contactCount;

public:
    PhoneBookManager() : m_contactCount(0) {}

    void addContact(const TelephoneBook& contact)
    {
        if (m_contactCount < 100) {
            m_contacts[m_contactCount++] = contact;
        }
        else {
            cout << "Phone book is full!" << endl;
        }
    }

    void removeContact(const char* name)
    {
        for (int i = 0; i < m_contactCount; ++i)
        {
            if (strcmp(m_contacts[i].getName(), name) == 0)
            {
                for (int j = i; j < m_contactCount - 1; ++j)
                {
                    m_contacts[j] = m_contacts[j + 1];
                }
                m_contactCount--;
                cout << "Contact " << name << " removed" << endl;
                return;
            }
        }
        cout << "Contact " << name << " not found" << endl;
    }

    void searchContact(const char* name) const
    {
        for (int i = 0; i < m_contactCount; ++i)
        {
            if (strcmp(m_contacts[i].getName(), name) == 0)
            {
                m_contacts[i].dataEntry();
                return;
            }
        }
        cout << "Contact " << name << " not found" << endl;
    }

    void showAllContacts() const
    {
        if (m_contactCount == 0) {
            cout << "No contacts available" << endl;
            return;
        }

        for (int i = 0; i < m_contactCount; ++i)
        {
            m_contacts[i].dataEntry();
            cout << "-------------------" << endl;
        }
    }

    void saveToFile(const char* filename) const
    {
        cout << "Saving file" << endl;
    }

    void loadFromFile(const char* filename)
    {
        cout << "Loading file" << endl;
    }
};


int main()
{
    PhoneBookManager phoneBookManager;

    phoneBookManager.addContact(TelephoneBook("Mark Wahlberg", "44444444444", "52", "*", "Actor, producer"));
    phoneBookManager.addContact(TelephoneBook("John Smith", "525252525252", "3", "4242424242", "Friend"));

    cout << "All Contacts:" << endl;
    phoneBookManager.showAllContacts();

    cout << "\nSearching for Mark Wahlberg:" << endl;
    phoneBookManager.searchContact("Mark Wahlberg");

    cout << "\nRemoving John Smith:" << endl;
    phoneBookManager.removeContact("John Smith");

    cout << "\nAll Contacts after removal:" << endl;
    phoneBookManager.showAllContacts();
}
