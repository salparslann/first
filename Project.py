import random
import json

def load_lost_items():
    try:
        with open("lost_items.json", "r") as file:
            data = file.read().strip()
            return json.loads(data) if data else {}
    except FileNotFoundError:
        return {}

def save_lost_items(lost_items):
    with open("lost_items.json", "w") as file:
        json.dump(lost_items, file, indent=4)

def generate_unique_id():
    return random.randint(100000, 999999)

def add_lost_item():
    lost_items = load_lost_items()
    print("Enter details for the lost item:")
    item_name = input("Item Name: ")
    brand = input("Brand: ")
    location = input("Location: ")
    finder_name = input("Your Name (Finder): ")
    unique_id = generate_unique_id()
    lost_items[str(unique_id)] = {  
        "Item Name": item_name,
        "Brand": brand,
        "Location": location,
        "Finder Name": finder_name,
        "Status": "Lost",
        "Found By": finder_name,
        "Taken By": None
    }
    save_lost_items(lost_items)
    print("Lost item recorded with ID:", unique_id)

def add_found_item():
    lost_items = load_lost_items()
    print("Enter details for the found item:")
    owner_name = input("Your Name (Owner): ")
    item_id = input("Enter the ID of the item: ")

    
    if item_id not in lost_items:
        print("Invalid ID. No matching item found.")
        return

    item_details = lost_items[item_id]
    if item_details["Status"] == "Found":
        print("Item with ID", item_id, "is already marked as Found.")
    else:
        item_details["Status"] = "Found"
        item_details["Found By"] = item_details["Finder Name"]
        item_details["Taken By"] = owner_name
        save_lost_items(lost_items)
        print(f"Item with ID {item_id} has been updated as Found and taken by {owner_name}.")

def search_item():
    lost_items = load_lost_items()
    print("Enter details to search for an item:")
    item_name = input("Item Name: ")
    brand = input("Brand: ")
    location = input("Location: ")
    matches = {}
    for item_id, item_details in lost_items.items():
        if (item_details["Item Name"] == item_name and
            item_details["Brand"] == brand and
            item_details["Location"] == location):
            matches[item_id] = item_details
    if matches:
        print("Matching items found:")
        for idx, (item_id, details) in enumerate(matches.items(), 1):
            print(idx, ". ID:", item_id, "Status:", details["Status"])
        choice = input("Enter the number of the item you want to inquire about: ")
        if not choice.isdigit() or not (1 <= int(choice) <= len(matches)):
            print("Invalid choice.")
            return
        selected_item_id = list(matches.keys())[int(choice) - 1]
        selected_item = matches[selected_item_id]
        print("Item Details: Name:", selected_item["Item Name"], ", Brand:", selected_item["Brand"], ", Location:", selected_item["Location"], ", Status:", selected_item["Status"])
        print("Found By:", selected_item["Found By"])
        print("Taken By:", selected_item["Taken By"])
    else:
        print("No matching items found.")

def remove_item():
    lost_items = load_lost_items()
    print("Enter the ID of the item to be removed:")
    item_id = input("Item ID: ")
    if item_id not in lost_items:
        print("Invalid input. Please enter a valid numeric ID.")
        return
    del lost_items[item_id]
    save_lost_items(lost_items)
    print("Item with ID", item_id, "has been removed.")

def ensure_json_file_exists():
    try:
        with open("lost_items.json", "x") as file:
            file.write("{}")
    except FileExistsError:
        pass

def main():
    ensure_json_file_exists()
    finished = False
    while not finished:
        print("\nMenu:")
        print("1. Report Lost Item")
        print("2. Report Found Item")
        print("3. Search for Item")
        print("4. Remove Item")
        print("5. Exit")
        choice = input("Enter your choice: ")

        if choice == "1":
            add_lost_item()
        elif choice == "2":
            add_found_item()
        elif choice == "3":
            search_item()
        elif choice == "4":
            remove_item()
        elif choice == "5":
            print("Exiting the system. Goodbye!")
            finished = True
        else:
            print("Invalid choice. Please try again.")

main()

